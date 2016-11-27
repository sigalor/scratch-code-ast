#include "Statement.hpp"



namespace ast
{
	const int Statement::uniqueId = 0x00000011;

	Statement::Statement(int newId) : Node(newId) { }
	Statement::Statement(int newId, std::shared_ptr<Node> newParent) : Node(newId, newParent) { }

	Statement::Statement() : Node(uniqueId) { }
	Statement::Statement(std::shared_ptr<Node> newParent) : Node(uniqueId, newParent) { }
}
