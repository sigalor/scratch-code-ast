/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/include/Conditional.hpp
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



#include <vector>
#include <memory>

#include "Node.hpp"
#include "Value.hpp"
#include "ControlFlowStatement.hpp"
#include "StatementList.hpp"



namespace ast
{
	class Conditional : public ControlFlowStatement
	{
		public:
			static const int									uniqueId;
	
		private:
			std::shared_ptr<Value>								condition;
			std::shared_ptr<StatementList>						consequenceBody;
			std::shared_ptr<StatementList>						alternativeBody;
		
		protected:
			Conditional(int newId);
			Conditional(int newId, std::shared_ptr<Node> newParent);
			Conditional(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<Value> newCondition, std::shared_ptr<StatementList> newConsequenceBody, std::shared_ptr<StatementList> newAlternativeBody);
		
		public:
			Conditional();
			Conditional(std::shared_ptr<Node> newParent);
			Conditional(std::shared_ptr<Node> newParent, std::shared_ptr<Value> newCondition, std::shared_ptr<StatementList> newConsequenceBody, std::shared_ptr<StatementList> newAlternativeBody);
			std::shared_ptr<Value>								getCondition();
			std::shared_ptr<StatementList>						getConsequenceBody();
			std::shared_ptr<StatementList>						getAlternativeBody();
			void												setCondition(std::shared_ptr<Value> newCondition);
			void												setConsequenceBody(std::shared_ptr<StatementList> newConsequenceBody);
			void												setAlternativeBody(std::shared_ptr<StatementList> newAlternativeBody);
	};
}
