#include "UnaryOperation.hpp"



namespace ast
{
	UnaryOperation::UnaryOperation(int newId) : Operation(newId), operation(Lexer::ParsedUnaryOperation::Invalid) { }
	UnaryOperation::UnaryOperation(int newId, std::shared_ptr<Node> newParent) : Operation(newId, newParent), operation(Lexer::ParsedUnaryOperation::Invalid) { }
	UnaryOperation::UnaryOperation(int newId, std::shared_ptr<Node> newParent, Lexer::ParsedUnaryOperation newOperation, std::shared_ptr<Value> newValue) : Operation(newId, newParent), operation(newOperation), value(newValue) { }

	UnaryOperation::UnaryOperation() : Operation(uniqueId), operation(Lexer::ParsedUnaryOperation::Invalid) { }
	UnaryOperation::UnaryOperation(std::shared_ptr<Node> newParent) : Operation(uniqueId, newParent), operation(Lexer::ParsedUnaryOperation::Invalid) { }
	UnaryOperation::UnaryOperation(std::shared_ptr<Node> newParent, Lexer::ParsedUnaryOperation newOperation, std::shared_ptr<Value> newValue) : Operation(uniqueId, newParent), operation(newOperation), value(newValue) { }
	
	Lexer::ParsedUnaryOperation UnaryOperation::getOperation()
	{
		return operation;
	}
	
	std::shared_ptr<Value> UnaryOperation::getValue()
	{
		return value;
	}
	
	void UnaryOperation::setOperation(Lexer::ParsedUnaryOperation newOperation)
	{
		operation = newOperation;
	}
	
	void UnaryOperation::setValue(std::shared_ptr<Value> newValue)
	{
		value = newValue;
	}
}
