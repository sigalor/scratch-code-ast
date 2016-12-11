/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/include/ast/FunctionCall.hpp
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
#include "FunctionDefinition.hpp"
#include "RValue.hpp"
#include "ValueList.hpp"



namespace ast
{
	class FunctionCall : public RValue
	{
		public:
			static const int									uniqueId;
	
		private:
			std::shared_ptr<FunctionDefinition>					assocFunc;
			std::shared_ptr<ValueList>							args;
		
		protected:
			FunctionCall(int newId);
			FunctionCall(int newId, std::shared_ptr<Node> newParent);
			FunctionCall(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<FunctionDefinition> newAssocFunc, std::shared_ptr<ValueList> newArgs);
		
		public:
			FunctionCall();
			FunctionCall(std::shared_ptr<Node> newParent);
			FunctionCall(std::shared_ptr<Node> newParent, std::shared_ptr<FunctionDefinition> newAssocFunc, std::shared_ptr<ValueList> newArgs);
			std::shared_ptr<FunctionDefinition>					getAssocFunc();
			std::shared_ptr<ValueList>							getArgs();
			virtual Lexer::ParsedVariableType					getEffectiveType() { return (assocFunc==nullptr ? Lexer::ParsedVariableType::Invalid : assocFunc->getReturnType()); }
			void												setAssocFunc(std::shared_ptr<FunctionDefinition> newAssocFunc);
			void												setArgs(std::shared_ptr<ValueList> newArgs);
	};
}
