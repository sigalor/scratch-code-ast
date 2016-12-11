/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/include/ast/VariableDefinition.hpp
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



#include <string>
#include <memory>

#include "Node.hpp"
#include "Statement.hpp"
#include "LexerTokenDefinitions.hpp"



namespace ast
{
	class VariableDefinition : public Statement
	{
		public:
			static const int									uniqueId;
	
		private:
			Lexer::ParsedVariableType							type;
			std::string											name;
		
		protected:
			VariableDefinition(int newId);
			VariableDefinition(int newId, std::shared_ptr<Node> newParent);
			VariableDefinition(int newId, std::shared_ptr<Node> newParent, Lexer::ParsedVariableType newType, const std::string& newName);
		
		public:
			VariableDefinition();
			VariableDefinition(std::shared_ptr<Node> newParent);
			VariableDefinition(std::shared_ptr<Node> newParent, Lexer::ParsedVariableType newType, const std::string& newName);
			Lexer::ParsedVariableType							getType();
			std::string&										getName();
			void												setType(Lexer::ParsedVariableType newType);
			void												setName(const std::string& newName);
	};
}
