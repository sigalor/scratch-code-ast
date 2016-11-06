#include "Operation.hpp"



namespace ast
{
	Operation::Operation(int newId) : RValue(newId) { }
	Operation::Operation(int newId, std::shared_ptr<Node> newParent) : RValue(newId, newParent) { }

	Operation::Operation() : RValue(uniqueId) { }
	Operation::Operation(std::shared_ptr<Node> newParent) : RValue(uniqueId, newParent) { }
}
