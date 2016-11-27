#include "VariableDefinitionList.hpp"



namespace ast
{
	const int VariableDefinitionList::uniqueId = 0x00000031;

	VariableDefinitionList::VariableDefinitionList(int newId) : Node(newId) { }
	VariableDefinitionList::VariableDefinitionList(int newId, std::shared_ptr<Node> newParent) : Node(newId, newParent) { }
	VariableDefinitionList::VariableDefinitionList(int newId, std::shared_ptr<Node> newParent, const std::vector<std::shared_ptr<VariableDefinition>>& newVarDefs) : Node(newId, newParent), varDefs(newVarDefs) { }

	VariableDefinitionList::VariableDefinitionList() : Node(uniqueId) { }
	VariableDefinitionList::VariableDefinitionList(std::shared_ptr<Node> newParent) : Node(uniqueId, newParent) { }
	VariableDefinitionList::VariableDefinitionList(std::shared_ptr<Node> newParent, const std::vector<std::shared_ptr<VariableDefinition>>& newVarDefs) : Node(uniqueId, newParent), varDefs(newVarDefs) { }
	
	std::vector<std::shared_ptr<VariableDefinition>>& VariableDefinitionList::getVarDefs()
	{
		return varDefs;
	}
	
	void VariableDefinitionList::addVarDef(std::shared_ptr<VariableDefinition> newVarDef)
	{
		varDefs.push_back(newVarDef);
	}
}
