#include "Value.hpp"



namespace ast
{
	Value::Value(int newId) : Statement(newId) { }
	Value::Value(int newId, std::shared_ptr<Node> newParent) : Statement(newId, newParent) { }

	Value::Value() : Statement(uniqueId) { }
	Value::Value(std::shared_ptr<Node> newParent) : Statement(uniqueId, newParent) { }
}
