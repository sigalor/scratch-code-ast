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
			virtual Lexer::ParsedVariableType					getEffectiveType()
			{
				switch(operation)
				{
					case Lexer::ParsedUnaryOperation::TypecastBool		: return Lexer::ParsedVariableType::Bool;
					case Lexer::ParsedUnaryOperation::TypecastInt		: return Lexer::ParsedVariableType::Int;
					case Lexer::ParsedUnaryOperation::TypecastReal		: return Lexer::ParsedVariableType::Real;
					case Lexer::ParsedUnaryOperation::TypecastString	: return Lexer::ParsedVariableType::String;
					default												: return (value==nullptr ? Lexer::ParsedVariableType::Invalid : value->getEffectiveType());
				}
			}
			virtual Lexer::ValueCategory						getValueCategory() { return getResultingValueCategory(); }
			Lexer::ValueCategory								getRequiredValueCategory();
			Lexer::ValueCategory								getResultingValueCategory();
			void												setOperation(Lexer::ParsedUnaryOperation newOperation);
			void												setValue(std::shared_ptr<Value> newValue);
	};
}
