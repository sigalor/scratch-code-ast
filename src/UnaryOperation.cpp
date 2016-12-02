/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/src/UnaryOperation.cpp
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



#include "UnaryOperation.hpp"



namespace ast
{
	const int UnaryOperation::uniqueId = 0x00013311;

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
	
	Lexer::ValueCategory UnaryOperation::getRequiredValueCategory()
	{
		return Lexer::getRequiredValueCategory(operation);
	}
	
	Lexer::ValueCategory UnaryOperation::getResultingValueCategory()
	{
		return Lexer::getResultingValueCategory(operation);
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
