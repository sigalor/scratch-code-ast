# build structure paths
PROJECT_NAME=scratch-code-ast
PROJECT_DEP_DIR=dep
PROJECT_EXT_DIR=ext
PROJECT_INCLUDE_DIR=include
PROJECT_LIB_DIR=lib
PROJECT_OBJ_DIR=obj
PROJECT_SRC_DIR=src

# lists of own files (not the *.l and *.y ones for flex and bison!)
CPP_FILES=$(wildcard $(PROJECT_SRC_DIR)/*.cpp)
OBJ_FILES=$(addprefix $(PROJECT_OBJ_DIR)/,$(notdir $(CPP_FILES:.cpp=.o)))
DEP_FILES=$(addprefix $(PROJECT_DEP_DIR)/,$(notdir $(CPP_FILES:.cpp=.d)))
FINAL_LIBRARY=$(PROJECT_LIB_DIR)/lib$(PROJECT_NAME).a

# include paths
INCLUDE_PATHS=-I$(PROJECT_INCLUDE_DIR) -I$(PROJECT_EXT_DIR)/boost

# names and options for used programs
CXX=g++
CXXFLAGS=-std=c++14 -g -Wall $(INCLUDE_PATHS)
AR=ar
ARFLAGS=rcs
DISCARD_OUTPUT=/dev/null
DIR_GUARD=@mkdir -p $(@D)



all: $(FINAL_LIBRARY)

$(FINAL_LIBRARY): $(OBJ_FILES)
	$(DIR_GUARD)
	$(AR) $(ARFLAGS) $@ $^

clean: clean_gen
	rm -f $(FINAL_LIBRARY) 2>&1 > $(DISCARD_OUTPUT)

clean_gen:
	rm -f $(PROJECT_OBJ_DIR)/* $(PROJECT_DEP_DIR)/* 2>&1 > $(DISCARD_OUTPUT)

$(PROJECT_DEP_DIR)/%.d: $(PROJECT_SRC_DIR)/%.cpp $(PROJECT_INCLUDE_DIR)/%.hpp
	$(DIR_GUARD)
	$(CXX) -E -MMD -MP -MT $(PROJECT_OBJ_DIR)/$(basename $(notdir $@)).o -MF $@ $(CXXFLAGS) $< > $(DISCARD_OUTPUT)

ifneq ($(MAKECMDGOALS), clean)
ifneq ($(MAKECMDGOALS), clean_gen)
-include $(DEP_FILES)
endif
endif



.SECONDEXPANSION:
$(PROJECT_OBJ_DIR)/%.o: $(PROJECT_SRC_DIR)/%.cpp
	$(DIR_GUARD)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.PHONY: clean clean_gen
