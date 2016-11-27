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
