#include "Operation.hpp"



namespace ast
{
	Operation::Operation(int newId) : Value(newId) { }
	Operation::Operation(int newId, std::shared_ptr<Node> newParent) : Value(newId, newParent) { }

	Operation::Operation() : Value(uniqueId) { }
	Operation::Operation(std::shared_ptr<Node> newParent) : Value(uniqueId, newParent) { }
}
