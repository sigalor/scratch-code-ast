#include "WhileLoop.hpp"



namespace ast
{
	WhileLoop::WhileLoop(int newId) : ControllableLoop(newId) { }
	WhileLoop::WhileLoop(int newId, std::shared_ptr<Node> newParent) : ControllableLoop(newId, newParent) { }
	WhileLoop::WhileLoop(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<Value> newCondition, std::shared_ptr<StatementList> newBody) : ControllableLoop(newId, newParent), condition(newCondition), body(newBody) { }

	WhileLoop::WhileLoop() : ControllableLoop(uniqueId) { }
	WhileLoop::WhileLoop(std::shared_ptr<Node> newParent) : ControllableLoop(uniqueId, newParent) { }
	WhileLoop::WhileLoop(std::shared_ptr<Node> newParent, std::shared_ptr<Value> newCondition, std::shared_ptr<StatementList> newBody) : ControllableLoop(uniqueId, newParent), condition(newCondition), body(newBody) { }
	
	std::shared_ptr<Value> WhileLoop::getCondition()
	{
		return condition;
	}
	
	std::shared_ptr<StatementList> WhileLoop::getBody()
	{
		return body;
	}
	
	void WhileLoop::setCondition(std::shared_ptr<Value> newCondition)
	{
		condition = newCondition;
	}
	
	void WhileLoop::setBody(std::shared_ptr<StatementList> newBody)
	{
		body = newBody;
	}
}
