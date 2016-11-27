#pragma once



#include <memory>

#include "LexerTokenDefinitions.hpp"
#include "Node.hpp"
#include "VariableDefinition.hpp"
#include "Value.hpp"



namespace ast
{
	class LValue : public Value
	{
		public:
			static const int									uniqueId;
	
		private:
			std::shared_ptr<VariableDefinition>					assocVarDef;
		
		protected:
			LValue(int newId);
			LValue(int newId, std::shared_ptr<Node> newParent);
			LValue(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<VariableDefinition> newAssocVarDef);
		
		public:
			LValue();
			LValue(std::shared_ptr<Node> newParent);
			LValue(std::shared_ptr<Node> newParent, std::shared_ptr<VariableDefinition> newAssocVarDef);
			std::shared_ptr<VariableDefinition>					getAssocVarDef();
			virtual Lexer::ParsedVariableType					getEffectiveType() { return (assocVarDef==nullptr ? Lexer::ParsedVariableType::Invalid : assocVarDef->getType()); }
			virtual Lexer::ValueCategory						getValueCategory() { return Lexer::ValueCategory::LValue; }
			void												setAssocVarDef(std::shared_ptr<VariableDefinition> newAssocVarDef);
	};
}
