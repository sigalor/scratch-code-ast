/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/src/VariableDefinitionList.cpp
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



#include <ast/VariableDefinitionList.hpp>



namespace ast
{
	const int VariableDefinitionList::uniqueId = 0x00000031;

	VariableDefinitionList::VariableDefinitionList(int newId) : Node(newId) { }
	VariableDefinitionList::VariableDefinitionList(int newId, std::shared_ptr<Node> newParent) : Node(newId, newParent) { }
	VariableDefinitionList::VariableDefinitionList(int newId, std::shared_ptr<Node> newParent, const std::vector<std::shared_ptr<VariableDefinition>>& newVarDefs) : Node(newId, newParent), varDefs(newVarDefs) { }

	VariableDefinitionList::VariableDefinitionList() : Node(uniqueId) { }
	VariableDefinitionList::VariableDefinitionList(std::shared_ptr<Node> newParent) : Node(uniqueId, newParent) { }
	VariableDefinitionList::VariableDefinitionList(std::shared_ptr<Node> newParent, const std::vector<std::shared_ptr<VariableDefinition>>& newVarDefs) : Node(uniqueId, newParent), varDefs(newVarDefs) { }
	
	std::vector<std::shared_ptr<VariableDefinition>>& VariableDefinitionList::getVarDefs()
	{
		return varDefs;
	}
	
	void VariableDefinitionList::addVarDef(std::shared_ptr<VariableDefinition> newVarDef)
	{
		varDefs.push_back(newVarDef);
	}
}
