#include "RValue.hpp"



namespace ast
{
	const int RValue::uniqueId = 0x00002311;

	RValue::RValue(int newId) : Value(newId) { }
	RValue::RValue(int newId, std::shared_ptr<Node> newParent) : Value(newId, newParent) { }

	RValue::RValue() : Value(uniqueId) { }
	RValue::RValue(std::shared_ptr<Node> newParent) : Value(uniqueId, newParent) { }
}
