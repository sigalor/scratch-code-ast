#include "Statement.hpp"



namespace ast
{
	Statement::Statement(int newId) : Node(newId) { }
	Statement::Statement(int newId, std::shared_ptr<Node> newParent) : Node(newId, newParent) { }

	Statement::Statement() : Node(uniqueId) { }
	Statement::Statement(std::shared_ptr<Node> newParent) : Node(uniqueId, newParent) { }
}
