/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/src/VariableDefinition.cpp
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



#include <ast/VariableDefinition.hpp>



namespace ast
{
	const int VariableDefinition::uniqueId = 0x00000111;

	VariableDefinition::VariableDefinition(int newId) : Statement(newId), type(Lexer::ParsedVariableType::Invalid) { }
	VariableDefinition::VariableDefinition(int newId, std::shared_ptr<Node> newParent) : Statement(newId, newParent), type(Lexer::ParsedVariableType::Invalid) { }
	VariableDefinition::VariableDefinition(int newId, std::shared_ptr<Node> newParent, Lexer::ParsedVariableType newType, const std::string& newName) : Statement(newId, newParent), type(newType), name(newName) { }

	VariableDefinition::VariableDefinition() : Statement(uniqueId), type(Lexer::ParsedVariableType::Invalid) { }
	VariableDefinition::VariableDefinition(std::shared_ptr<Node> newParent) : Statement(uniqueId, newParent), type(Lexer::ParsedVariableType::Invalid) { }
	VariableDefinition::VariableDefinition(std::shared_ptr<Node> newParent, Lexer::ParsedVariableType newType, const std::string& newName) : Statement(uniqueId, newParent), type(newType), name(newName) { }
	
	Lexer::ParsedVariableType VariableDefinition::getType()
	{
		return type;
	}
	
	std::string& VariableDefinition::getName()
	{
		return name;
	}
	
	void VariableDefinition::setType(Lexer::ParsedVariableType newType)
	{
		type = newType;
	}
	
	void VariableDefinition::setName(const std::string& newName)
	{
		name = newName;
	}
}
