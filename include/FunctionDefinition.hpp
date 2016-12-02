/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/include/FunctionDefinition.hpp
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
#include "StatementList.hpp"
#include "VariableDefinitionList.hpp"
#include "LexerTokenDefinitions.hpp"



namespace ast
{
	class FunctionDefinition : public Statement
	{
		public:
			static const int									uniqueId;
	
		private:
			Lexer::ParsedVariableType							returnType;
			std::string											name;
			std::shared_ptr<VariableDefinitionList>				args;
			std::shared_ptr<StatementList>						body;
		
		protected:
			FunctionDefinition(int newId);
			FunctionDefinition(int newId, std::shared_ptr<Node> newParent);
			FunctionDefinition(int newId, std::shared_ptr<Node> newParent, Lexer::ParsedVariableType newReturnType, const std::string& newName, std::shared_ptr<VariableDefinitionList> newArgs, std::shared_ptr<StatementList> newBody);
		
		public:
			FunctionDefinition();
			FunctionDefinition(std::shared_ptr<Node> newParent);
			FunctionDefinition(std::shared_ptr<Node> newParent, Lexer::ParsedVariableType newReturnType, const std::string& newName, std::shared_ptr<VariableDefinitionList> newArgs, std::shared_ptr<StatementList> newBody);
			Lexer::ParsedVariableType							getReturnType();
			const std::string&									getName();
			std::shared_ptr<VariableDefinitionList>				getArgs();
			std::shared_ptr<StatementList>						getBody();
			void												setReturnType(Lexer::ParsedVariableType newReturnType);
			void												setName(const std::string& newName);
			void												setArgs(std::shared_ptr<VariableDefinitionList> newArgs);
			void												setBody(std::shared_ptr<StatementList> newBody);
	};
}
