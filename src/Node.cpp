/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/src/Node.cpp
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



#include <ast/Node.hpp>



namespace ast
{
	const int Node::uniqueId = 0x00000001;

	Node::Node(int newId) : id(newId) { }
	Node::Node(int newId, std::shared_ptr<Node> newParent) : id(newId), parent(newParent) { }

	Node::Node() : id(uniqueId) { }
	Node::Node(std::shared_ptr<Node> newParent) : id(uniqueId), parent(newParent) { }
	Node::~Node() { }
	
	int Node::getId()
	{
		return id;
	}
	
	std::shared_ptr<Node> Node::getParent()
	{
		return parent;
	}
	
	void Node::setParent(std::shared_ptr<Node> newParent)
	{
		parent = newParent;
	}
	
	std::shared_ptr<Node> Node::searchParents(std::function<bool(std::shared_ptr<Node>)> condition, std::size_t* steps)
	{
		std::size_t retSteps = 1;																			//the first step is this instance's parent itself
		std::shared_ptr<Node> subject(parent);
		
		while(subject != nullptr)
		{
			if(condition(subject))																			//I think a lambda is the most efficient way to avoid code duplication
			{
				if(steps != nullptr)
					*steps = retSteps;
				return subject;
			}
			subject = subject->getParent();
			retSteps++;
		}
		
		return nullptr;
	}
}
