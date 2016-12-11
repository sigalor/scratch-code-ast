/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/include/ast/UnaryOperation.hpp
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
	class UnaryOperation : public Operation
	{
		public:
			static const int									uniqueId;
	
		private:
			Lexer::ParsedUnaryOperation							operation;
			std::shared_ptr<Value>								value;
		
		protected:
			UnaryOperation(int newId);
			UnaryOperation(int newId, std::shared_ptr<Node> newParent);
			UnaryOperation(int newId, std::shared_ptr<Node> newParent, Lexer::ParsedUnaryOperation newOperation, std::shared_ptr<Value> newValue);
		
		public:
			UnaryOperation();
			UnaryOperation(std::shared_ptr<Node> newParent);
			UnaryOperation(std::shared_ptr<Node> newParent, Lexer::ParsedUnaryOperation newOperation, std::shared_ptr<Value> newValue);
			Lexer::ParsedUnaryOperation							getOperation();
			std::shared_ptr<Value>								getValue();
			virtual Lexer::ParsedVariableType					getEffectiveType() { return Lexer::getResultingType(operation, value==nullptr ? Lexer::ParsedVariableType::Invalid : value->getEffectiveType()); }
			virtual Lexer::ValueCategory						getValueCategory() { return getResultingValueCategory(); }
			Lexer::ValueCategory								getRequiredValueCategory();
			Lexer::ValueCategory								getResultingValueCategory();
			void												setOperation(Lexer::ParsedUnaryOperation newOperation);
			void												setValue(std::shared_ptr<Value> newValue);
	};
}
