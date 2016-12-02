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
	Conditional::Conditional(int newId, std::shared_ptr<Node> newParent, std::vector<std::shared_ptr<Value>> newConditions, std::vector<std::shared_ptr<StatementList>> newConsequenceBodies, std::shared_ptr<StatementList> newAlternativeBody) : ControlFlowStatement(newId, newParent), conditions(newConditions), consequenceBodies(newConsequenceBodies), alternativeBody(newAlternativeBody) { }

	Conditional::Conditional() : ControlFlowStatement(uniqueId) { }
	Conditional::Conditional(std::shared_ptr<Node> newParent) : ControlFlowStatement(uniqueId, newParent) { }
	Conditional::Conditional(std::shared_ptr<Node> newParent, std::vector<std::shared_ptr<Value>> newConditions, std::vector<std::shared_ptr<StatementList>> newConsequenceBodies, std::shared_ptr<StatementList> newAlternativeBody) : ControlFlowStatement(uniqueId, newParent), conditions(newConditions), consequenceBodies(newConsequenceBodies), alternativeBody(newAlternativeBody) { }
	
	std::vector<std::shared_ptr<Value>>& Conditional::getConditions()
	{
		return conditions;
	}
	
	std::vector<std::shared_ptr<StatementList>>& Conditional::getConsequenceBodies()
	{
		return consequenceBodies;
	}
	
	std::shared_ptr<StatementList> Conditional::getAlternativeBody()
	{
		return alternativeBody;
	}
	
	void Conditional::addCondition(std::shared_ptr<Value> newCondition)
	{
		conditions.push_back(newCondition);
	}
	
	void Conditional::addConsequenceBody(std::shared_ptr<StatementList> newConsequenceBody)
	{
		consequenceBodies.push_back(newConsequenceBody);
	}
	
	void Conditional::setAlternativeBody(std::shared_ptr<StatementList> newAlternativeBody)
	{
		alternativeBody = newAlternativeBody;
	}
}
