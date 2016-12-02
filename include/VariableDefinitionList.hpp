/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/include/VariableDefinitionList.hpp
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */



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
			static const int									uniqueId;
	
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
