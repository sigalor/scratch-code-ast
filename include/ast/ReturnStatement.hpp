/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/include/ast/ReturnStatement.hpp
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
#include "ControlFlowStatement.hpp"
#include "FunctionDefinition.hpp"



namespace ast
{
	class ReturnStatement : public ControlFlowStatement
	{
		public:
			static const int									uniqueId;
	
		private:
			std::shared_ptr<Value>								value;
			std::shared_ptr<FunctionDefinition>					targetFunc;
		
		protected:
			ReturnStatement(int newId);
			ReturnStatement(int newId, std::shared_ptr<Node> newParent);
			ReturnStatement(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<Value> newValue, std::shared_ptr<FunctionDefinition> newTargetFunc);
		
		public:
			ReturnStatement();
			ReturnStatement(std::shared_ptr<Node> newParent);
			ReturnStatement(std::shared_ptr<Node> newParent, std::shared_ptr<Value> newValue, std::shared_ptr<FunctionDefinition> newTargetFunc);
			std::shared_ptr<Value>								getValue();
			std::shared_ptr<FunctionDefinition>					getTargetFunc();
			void												setValue(std::shared_ptr<Value> newValue);
			void												setTargetFunc(std::shared_ptr<FunctionDefinition> newTargetFunc);
	};
}
