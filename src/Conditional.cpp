#include "Conditional.hpp"



namespace ast
{
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
