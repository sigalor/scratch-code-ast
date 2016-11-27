#include "ForLoop.hpp"



namespace ast
{
	const int ForLoop::uniqueId = 0x00012411;

	ForLoop::ForLoop(int newId) : ControllableLoop(newId) { }
	ForLoop::ForLoop(int newId, std::shared_ptr<Node> newParent) : ControllableLoop(newId, newParent) { }
	ForLoop::ForLoop(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<Value> newInitialization, std::shared_ptr<Value> newCondition, std::shared_ptr<Value> newAfterthought, std::shared_ptr<StatementList> newBody) : ControllableLoop(newId, newParent), initialization(newInitialization), condition(newCondition), afterthought(newAfterthought), body(newBody) { }

	ForLoop::ForLoop() : ControllableLoop(uniqueId) { }
	ForLoop::ForLoop(std::shared_ptr<Node> newParent) : ControllableLoop(uniqueId, newParent) { }
	ForLoop::ForLoop(std::shared_ptr<Node> newParent, std::shared_ptr<Value> newInitialization, std::shared_ptr<Value> newCondition, std::shared_ptr<Value> newAfterthought, std::shared_ptr<StatementList> newBody) : ControllableLoop(uniqueId, newParent), initialization(newInitialization), condition(newCondition), afterthought(newAfterthought), body(newBody) { }
	
	std::shared_ptr<Value> ForLoop::getInitialization()
	{
		return initialization;
	}
	
	std::shared_ptr<Value> ForLoop::getCondition()
	{
		return condition;
	}
	
	std::shared_ptr<Value> ForLoop::getAfterthought()
	{
		return afterthought;
	}
	
	std::shared_ptr<StatementList> ForLoop::getBody()
	{
		return body;
	}
	
	void ForLoop::setInitialization(std::shared_ptr<Value> newInitialization)
	{
		initialization = newInitialization;
	}
	
	void ForLoop::setCondition(std::shared_ptr<Value> newCondition)
	{
		condition = newCondition;
	}
	
	void ForLoop::setAfterthought(std::shared_ptr<Value> newAfterthought)
	{
		afterthought = newAfterthought;
	}
	
	void ForLoop::setBody(std::shared_ptr<StatementList> newBody)
	{
		body = newBody;
	}
}
