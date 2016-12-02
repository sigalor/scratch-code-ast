/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/src/ValueList.cpp
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */



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
