/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/include/ast/StatementList.hpp
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
#include "Statement.hpp"



namespace ast
{
	class StatementList : public Node
	{
		public:
			static const int									uniqueId;
	
		private:
			std::vector<std::shared_ptr<Statement>>				statements;
		
		protected:
			StatementList(int newId);
			StatementList(int newId, std::shared_ptr<Node> newParent);
			StatementList(int newId, std::shared_ptr<Node> newParent, const std::vector<std::shared_ptr<Statement>>& newStatements);
		
		public:
			StatementList();
			StatementList(std::shared_ptr<Node> newParent);
			StatementList(std::shared_ptr<Node> newParent, const std::vector<std::shared_ptr<Statement>>& newStatements);
			std::vector<std::shared_ptr<Statement>>&			getStatements();
			void												addStatement(std::shared_ptr<Statement> newStatement);
	};
}
