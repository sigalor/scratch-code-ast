/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/src/LValue.cpp
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



#include <ast/LValue.hpp>



namespace ast
{
	const int LValue::uniqueId = 0x00001311;

	LValue::LValue(int newId) : Value(newId) { }
	LValue::LValue(int newId, std::shared_ptr<Node> newParent) : Value(newId, newParent) { }
	LValue::LValue(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<VariableDefinition> newAssocVarDef) : Value(newId, newParent), assocVarDef(newAssocVarDef) { }

	LValue::LValue() : Value(uniqueId) { }
	LValue::LValue(std::shared_ptr<Node> newParent) : Value(uniqueId, newParent) { }
	LValue::LValue(std::shared_ptr<Node> newParent, std::shared_ptr<VariableDefinition> newAssocVarDef) : Value(uniqueId, newParent), assocVarDef(newAssocVarDef) { }
	
	std::shared_ptr<VariableDefinition> LValue::getAssocVarDef()
	{
		return assocVarDef;
	}
	
	void LValue::setAssocVarDef(std::shared_ptr<VariableDefinition> newAssocVarDef)
	{
		assocVarDef = newAssocVarDef;
	}
}
