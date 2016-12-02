/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/include/LValue.hpp
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
