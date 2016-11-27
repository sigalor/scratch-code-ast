#pragma once



#include <iostream>
#include <iomanip>
#include <memory>

#include "LexerTokenDefinitions.hpp"
#include "Node.hpp"
#include "Statement.hpp"



namespace ast
{
	class Value : public Statement
	{
		public:
			static const int									uniqueId;
	
		private:
		
		protected:
			Value(int newId);
			Value(int newId, std::shared_ptr<Node> newParent);
		
		public:
			Value();
			Value(std::shared_ptr<Node> newParent);
			virtual Lexer::ParsedVariableType					getEffectiveType() { return Lexer::ParsedVariableType::Invalid; }
			virtual Lexer::ValueCategory						getValueCategory() { return Lexer::ValueCategory::Invalid; }
	};
}
