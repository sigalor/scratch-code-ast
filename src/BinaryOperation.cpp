/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/src/BinaryOperation.cpp
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



#include <ast/BinaryOperation.hpp>



namespace ast
{
	const int BinaryOperation::uniqueId = 0x00023311;

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
