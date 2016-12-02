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
			virtual Lexer::ParsedVariableType					getEffectiveType()
			{
				switch(operation)
				{
					case Lexer::ParsedBinaryOperation::LogicalAnd			:
					case Lexer::ParsedBinaryOperation::LogicalOr			:
					case Lexer::ParsedBinaryOperation::LessThan				:
					case Lexer::ParsedBinaryOperation::LessThanOrEqual		:
					case Lexer::ParsedBinaryOperation::GreaterThan			:
					case Lexer::ParsedBinaryOperation::GreaterThanOrEqual	:
					case Lexer::ParsedBinaryOperation::Equal				:
					case Lexer::ParsedBinaryOperation::NotEqual				: return Lexer::ParsedVariableType::Bool;		//logical and comparison operators always result in bool
					default													: return (lhs==nullptr ? (rhs==nullptr ? Lexer::ParsedVariableType::Invalid : rhs->getEffectiveType()) : lhs->getEffectiveType());		//it is guaranteed by the parser that "lhs" and "rhs" have the same type, so it's irrelevant wheather "lhs" or "rhs" is used here
				}
			}
			virtual Lexer::ValueCategory						getValueCategory() { return getResultingValueCategory(); }
			Lexer::ValueCategory								getRequiredLhsValueCategory();
			Lexer::ValueCategory								getRequiredRhsValueCategory();
			Lexer::ValueCategory								getResultingValueCategory();
			void												setLhs(std::shared_ptr<Value> newLhs);
			void												setOperation(Lexer::ParsedBinaryOperation newOperation);
			void												setRhs(std::shared_ptr<Value> newRhs);
	};
}
