#include "Node.hpp"



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
