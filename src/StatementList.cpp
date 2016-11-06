#include "StatementList.hpp"



namespace ast
{
	StatementList::StatementList(int newId) : Node(newId) { }
	StatementList::StatementList(int newId, std::shared_ptr<Node> newParent) : Node(newId, newParent) { }
	StatementList::StatementList(int newId, std::shared_ptr<Node> newParent, const std::vector<std::shared_ptr<Statement>>& newStatements) : Node(newId, newParent), statements(newStatements) { }

	StatementList::StatementList() : Node(uniqueId) { }
	StatementList::StatementList(std::shared_ptr<Node> newParent) : Node(uniqueId, newParent) { }
	StatementList::StatementList(std::shared_ptr<Node> newParent, const std::vector<std::shared_ptr<Statement>>& newStatements) : Node(uniqueId, newParent), statements(newStatements) { }
	
	std::vector<std::shared_ptr<Statement>>& StatementList::getStatements()
	{
		return statements;
	}
	
	void StatementList::addStatement(std::shared_ptr<Statement> newStatement)
	{
		statements.push_back(newStatement);
	}
}
