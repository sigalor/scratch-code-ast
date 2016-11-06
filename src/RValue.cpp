#include "RValue.hpp"



namespace ast
{
	RValue::RValue(int newId) : Value(newId) { }
	RValue::RValue(int newId, std::shared_ptr<Node> newParent) : Value(newId, newParent) { }

	RValue::RValue() : Value(uniqueId) { }
	RValue::RValue(std::shared_ptr<Node> newParent) : Value(uniqueId, newParent) { }
}
