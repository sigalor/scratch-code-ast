/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/include/ast/ForLoop.hpp
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
#include "ControllableLoop.hpp"
#include "StatementList.hpp"



namespace ast
{
	class ForLoop : public ControllableLoop																			//for loops are constructed like this: for(initialization; condition; afterthought) { body; }
	{
		public:
			static const int									uniqueId;
	
		private:
			std::shared_ptr<Value>								initialization, condition, afterthought;
			std::shared_ptr<StatementList>						body;
		
		protected:
			ForLoop(int newId);
			ForLoop(int newId, std::shared_ptr<Node> newParent);
			ForLoop(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<Value> newInitialization, std::shared_ptr<Value> newCondition, std::shared_ptr<Value> newAfterthought, std::shared_ptr<StatementList> newBody);
		
		public:
			ForLoop();
			ForLoop(std::shared_ptr<Node> newParent);
			ForLoop(std::shared_ptr<Node> newParent, std::shared_ptr<Value> newInitialization, std::shared_ptr<Value> newCondition, std::shared_ptr<Value> newAfterthought, std::shared_ptr<StatementList> newBody);
			std::shared_ptr<Value>								getInitialization();
			std::shared_ptr<Value>								getCondition();
			std::shared_ptr<Value>								getAfterthought();
			std::shared_ptr<StatementList>						getBody();
			void												setInitialization(std::shared_ptr<Value> newInitialization);
			void												setCondition(std::shared_ptr<Value> newCondition);
			void												setAfterthought(std::shared_ptr<Value> newAfterthought);
			void												setBody(std::shared_ptr<StatementList> newBody);
	};
}
