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
			static const int									uniqueId = 0x00132311;
	
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
			void												setOperation(Lexer::ParsedUnaryOperation newOperation);
			void												setValue(std::shared_ptr<Value> newValue);
	};
}
