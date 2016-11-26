#include "BinaryOperation.hpp"



namespace ast
{
	BinaryOperation::BinaryOperation(int newId) : Operation(newId), operation(Lexer::ParsedBinaryOperation::Invalid) { }
	BinaryOperation::BinaryOperation(int newId, std::shared_ptr<Node> newParent) : Operation(newId, newParent), operation(Lexer::ParsedBinaryOperation::Invalid) { }
	BinaryOperation::BinaryOperation(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<Value> newLhs, Lexer::ParsedBinaryOperation newOperation, std::shared_ptr<Value> newRhs) : Operation(newId, newParent), lhs(newLhs), operation(newOperation), rhs(newRhs) { }
	
	BinaryOperation::BinaryOperation() : Operation(uniqueId), operation(Lexer::ParsedBinaryOperation::Invalid) { }
	BinaryOperation::BinaryOperation(std::shared_ptr<Node> newParent) : Operation(uniqueId, newParent), operation(Lexer::ParsedBinaryOperation::Invalid) { }
	BinaryOperation::BinaryOperation(std::shared_ptr<Node> newParent, std::shared_ptr<Value> newLhs, Lexer::ParsedBinaryOperation newOperation, std::shared_ptr<Value> newRhs) : Operation(uniqueId, newParent), lhs(newLhs), operation(newOperation), rhs(newRhs) { }
	
	std::shared_ptr<Value> BinaryOperation::getLhs()
	{
		return lhs;
	}
	
	Lexer::ParsedBinaryOperation BinaryOperation::getOperation()
	{
		return operation;
	}
	
	std::shared_ptr<Value> BinaryOperation::getRhs()
	{
		return rhs;
	}
	
	Lexer::ValueCategory BinaryOperation::getRequiredLhsValueCategory()
	{
		return Lexer::getRequiredLhsValueCategory(operation);
	}
	
	Lexer::ValueCategory BinaryOperation::getRequiredRhsValueCategory()
	{
		return Lexer::getRequiredRhsValueCategory(operation);
	}
	
	Lexer::ValueCategory BinaryOperation::getResultingValueCategory()
	{
		return Lexer::getResultingValueCategory(operation);
	}
	
	void BinaryOperation::setLhs(std::shared_ptr<Value> newLhs)
	{
		lhs = newLhs;
	}
	
	void BinaryOperation::setOperation(Lexer::ParsedBinaryOperation newOperation)
	{
		operation = newOperation;
	}
	
	void BinaryOperation::setRhs(std::shared_ptr<Value> newRhs)
	{
		rhs = newRhs;
	}
}
