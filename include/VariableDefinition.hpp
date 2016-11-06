#pragma once



#include <string>
#include <memory>

#include "Node.hpp"
#include "Statement.hpp"
#include "LexerTokenDefinitions.hpp"



namespace ast
{
	class VariableDefinition : public Statement
	{
		public:
			static const int									uniqueId = 0x00000111;
	
		private:
			Lexer::ParsedVariableType							type;
			std::string											name;
		
		protected:
			VariableDefinition(int newId);
			VariableDefinition(int newId, std::shared_ptr<Node> newParent);
			VariableDefinition(int newId, std::shared_ptr<Node> newParent, Lexer::ParsedVariableType newType, const std::string& newName);
		
		public:
			VariableDefinition();
			VariableDefinition(std::shared_ptr<Node> newParent);
			VariableDefinition(std::shared_ptr<Node> newParent, Lexer::ParsedVariableType newType, const std::string& newName);
			Lexer::ParsedVariableType							getType();
			std::string&										getName();
			void												setType(Lexer::ParsedVariableType newType);
			void												setName(const std::string& newName);
	};
}
