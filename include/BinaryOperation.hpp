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
			static const int									uniqueId = 0x00023311;
	
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
			void												setLhs(std::shared_ptr<Value> newLhs);
			void												setOperation(Lexer::ParsedBinaryOperation newOperation);
			void												setRhs(std::shared_ptr<Value> newRhs);
	};
}
