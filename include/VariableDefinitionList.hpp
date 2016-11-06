#pragma once



#include <vector>
#include <memory>

#include "Node.hpp"
#include "VariableDefinition.hpp"



namespace ast
{
	class VariableDefinitionList : public Node																	//needed from FunctionDefinition
	{
		public:
			static const int									uniqueId = 0x00000031;
	
		private:
			std::vector<std::shared_ptr<VariableDefinition>>	varDefs;
		
		protected:
			VariableDefinitionList(int newId);
			VariableDefinitionList(int newId, std::shared_ptr<Node> newParent);
			VariableDefinitionList(int newId, std::shared_ptr<Node> newParent, const std::vector<std::shared_ptr<VariableDefinition>>& newVarDefs);
		
		public:
			VariableDefinitionList();
			VariableDefinitionList(std::shared_ptr<Node> newParent);
			VariableDefinitionList(std::shared_ptr<Node> newParent, const std::vector<std::shared_ptr<VariableDefinition>>& newVarDefs);
			std::vector<std::shared_ptr<VariableDefinition>>&	getVarDefs();
			void												addVarDef(std::shared_ptr<VariableDefinition> newVarDef);
	};
}
