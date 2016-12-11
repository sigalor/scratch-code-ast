/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/include/ast/BinaryOperation.hpp
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



#pragma once



#include <memory>

#include "Node.hpp"
#include "Value.hpp"
#include "Operation.hpp"
#include "LexerTokenDefinitions.hpp"



namespace ast
{
	class BinaryOperation : public Operation																		//arithmetic (+, -, *, /), logical (&&, ||), comparative (<, <=, >, >=, ==, !=), binary (&, |, ^)...
	{
		public:
			static const int									uniqueId;
	
		private:
			std::shared_ptr<Value>								lhs;
			Lexer::ParsedBinaryOperation						operation;
			std::shared_ptr<Value>								rhs;
		
		protected:
			BinaryOperation(int newId);
			BinaryOperation(int newId, std::shared_ptr<Node> newParent);
			BinaryOperation(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<Value> newLhs, Lexer::ParsedBinaryOperation newOperation, std::shared_ptr<Value> newRhs);
		
		public:
			BinaryOperation();
			BinaryOperation(std::shared_ptr<Node> newParent);
			BinaryOperation(std::shared_ptr<Node> newParent, std::shared_ptr<Value> newLhs, Lexer::ParsedBinaryOperation newOperation, std::shared_ptr<Value> newRhs);
			std::shared_ptr<Value>								getLhs();
			Lexer::ParsedBinaryOperation						getOperation();
			std::shared_ptr<Value>								getRhs();
			virtual Lexer::ParsedVariableType					getEffectiveType() { return Lexer::getResultingType(operation, lhs==nullptr ? (rhs==nullptr ? Lexer::ParsedVariableType::Invalid : rhs->getEffectiveType()) : lhs->getEffectiveType()); }		//it is guaranteed by the parser that "lhs" and "rhs" have the same type, so it's irrelevant wheather "lhs" or "rhs" is used here
			virtual Lexer::ValueCategory						getValueCategory() { return getResultingValueCategory(); }
			Lexer::ValueCategory								getRequiredLhsValueCategory();
			Lexer::ValueCategory								getRequiredRhsValueCategory();
			Lexer::ValueCategory								getResultingValueCategory();
			void												setLhs(std::shared_ptr<Value> newLhs);
			void												setOperation(Lexer::ParsedBinaryOperation newOperation);
			void												setRhs(std::shared_ptr<Value> newRhs);
	};
}
