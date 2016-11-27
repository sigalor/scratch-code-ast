#include "ValueList.hpp"



namespace ast
{
	const int ValueList::uniqueId = 0x00000041;

	ValueList::ValueList(int newId) : Node(newId) { }
	ValueList::ValueList(int newId, std::shared_ptr<Node> newParent) : Node(newId, newParent) { }
	ValueList::ValueList(int newId, std::shared_ptr<Node> newParent, const std::vector<std::shared_ptr<Value>>& newValues) : Node(newId, newParent), values(newValues) { }

	ValueList::ValueList() : Node(uniqueId) { }
	ValueList::ValueList(std::shared_ptr<Node> newParent) : Node(uniqueId, newParent) { }
	ValueList::ValueList(std::shared_ptr<Node> newParent, const std::vector<std::shared_ptr<Value>>& newValues) : Node(uniqueId, newParent), values(newValues) { }
	
	std::vector<std::shared_ptr<Value>>& ValueList::getValues()
	{
		return values;
	}
	
	void ValueList::addValue(std::shared_ptr<Value> newVal)
	{
		values.push_back(newVal);
	}
}
