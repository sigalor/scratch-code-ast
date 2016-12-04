/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/src/Conditional.cpp
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



#include "Conditional.hpp"



namespace ast
{
	const int Conditional::uniqueId = 0x00001411;

	Conditional::Conditional(int newId) : ControlFlowStatement(newId) { }
	Conditional::Conditional(int newId, std::shared_ptr<Node> newParent) : ControlFlowStatement(newId, newParent) { }
	Conditional::Conditional(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<Value> newCondition, std::shared_ptr<StatementList> newConsequenceBody, std::shared_ptr<StatementList> newAlternativeBody) : ControlFlowStatement(newId, newParent), condition(newCondition), consequenceBody(newConsequenceBody), alternativeBody(newAlternativeBody) { }

	Conditional::Conditional() : ControlFlowStatement(uniqueId) { }
	Conditional::Conditional(std::shared_ptr<Node> newParent) : ControlFlowStatement(uniqueId, newParent) { }
	Conditional::Conditional(std::shared_ptr<Node> newParent, std::shared_ptr<Value> newCondition, std::shared_ptr<StatementList> newConsequenceBody, std::shared_ptr<StatementList> newAlternativeBody) : ControlFlowStatement(uniqueId, newParent), condition(newCondition), consequenceBody(newConsequenceBody), alternativeBody(newAlternativeBody) { }
	
	std::shared_ptr<Value> Conditional::getCondition()
	{
		return condition;
	}
	
	std::shared_ptr<StatementList> Conditional::getConsequenceBody()
	{
		return consequenceBody;
	}
	
	std::shared_ptr<StatementList> Conditional::getAlternativeBody()
	{
		return alternativeBody;
	}
	
	void Conditional::setCondition(std::shared_ptr<Value> newCondition)
	{
		condition = newCondition;
	}
	
	void Conditional::setConsequenceBody(std::shared_ptr<StatementList> newConsequenceBody)
	{
		consequenceBody = newConsequenceBody;
	}
	
	void Conditional::setAlternativeBody(std::shared_ptr<StatementList> newAlternativeBody)
	{
		alternativeBody = newAlternativeBody;
	}
}
