#include "ReturnStatement.hpp"



namespace ast
{
	ReturnStatement::ReturnStatement(int newId) : ControlFlowStatement(newId) { }
	ReturnStatement::ReturnStatement(int newId, std::shared_ptr<Node> newParent) : ControlFlowStatement(newId, newParent) { }
	ReturnStatement::ReturnStatement(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<Value> newValue, std::shared_ptr<FunctionDefinition> newTargetFunc) : ControlFlowStatement(newId, newParent), value(newValue), targetFunc(newTargetFunc) { }

	ReturnStatement::ReturnStatement() : ControlFlowStatement(uniqueId) { }
	ReturnStatement::ReturnStatement(std::shared_ptr<Node> newParent) : ControlFlowStatement(uniqueId, newParent) { }
	ReturnStatement::ReturnStatement(std::shared_ptr<Node> newParent, std::shared_ptr<Value> newValue, std::shared_ptr<FunctionDefinition> newTargetFunc) : ControlFlowStatement(uniqueId, newParent), value(newValue), targetFunc(newTargetFunc) { }
	
	std::shared_ptr<Value> ReturnStatement::getValue()
	{
		return value;
	}
	
	std::shared_ptr<FunctionDefinition> ReturnStatement::getTargetFunc()
	{
		return targetFunc;
	}
	
	void ReturnStatement::setValue(std::shared_ptr<Value> newValue)
	{
		value = newValue;
	}
	
	void ReturnStatement::setTargetFunc(std::shared_ptr<FunctionDefinition> newTargetFunc)
	{
		targetFunc = newTargetFunc;
	}
}
