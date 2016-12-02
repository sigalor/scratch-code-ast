/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/src/ReturnStatement.cpp
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



#include "ReturnStatement.hpp"



namespace ast
{
	const int ReturnStatement::uniqueId = 0x00004411;

	ReturnStatement::ReturnStatement(int newId) : ControlFlowStatement(newId) { }
	ReturnStatement::ReturnStatement(int newId, std::shared_ptr<Node> newParent) : ControlFlowStatement(newId, newParent) { }
	ReturnStatement::ReturnStatement(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<Value> newValue, std::shared_ptr<FunctionDefinition> newTargetFunc) : ControlFlowStatement(newId, newParent), value(newValue), targetFunc(newTargetFunc) { }

	ReturnStatement::ReturnStatement() : ControlFlowStatement(uniqueId) { }
	ReturnStatement::ReturnStatement(std::shared_ptr<Node> newParent) : ControlFlowStatement(uniqueId, newParent) { }
	ReturnStatement::ReturnStatement(std::shared_ptr<Node> newParent, std::shared_ptr<Value> newValue, std::shared_ptr<FunctionDefinition> newTargetFunc) : ControlFlowStatement(uniqueId, newParent), value(newValue), targetFunc(newTargetFunc) { }
	
	std::shared_ptr<Value> ReturnStatement::getValue()
	{
		return value;
	}
	
	std::shared_ptr<FunctionDefinition> ReturnStatement::getTargetFunc()
	{
		return targetFunc;
	}
	
	void ReturnStatement::setValue(std::shared_ptr<Value> newValue)
	{
		value = newValue;
	}
	
	void ReturnStatement::setTargetFunc(std::shared_ptr<FunctionDefinition> newTargetFunc)
	{
		targetFunc = newTargetFunc;
	}
}
