#include "LValue.hpp"



namespace ast
{
	LValue::LValue(int newId) : Value(newId) { }
	LValue::LValue(int newId, std::shared_ptr<Node> newParent) : Value(newId, newParent) { }
	LValue::LValue(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<VariableDefinition> newAssocVarDef) : Value(newId, newParent), assocVarDef(newAssocVarDef) { }

	LValue::LValue() : Value(uniqueId) { }
	LValue::LValue(std::shared_ptr<Node> newParent) : Value(uniqueId, newParent) { }
	LValue::LValue(std::shared_ptr<Node> newParent, std::shared_ptr<VariableDefinition> newAssocVarDef) : Value(uniqueId, newParent), assocVarDef(newAssocVarDef) { }
	
	std::shared_ptr<VariableDefinition> LValue::getAssocVarDef()
	{
		return assocVarDef;
	}
	
	void LValue::setAssocVarDef(std::shared_ptr<VariableDefinition> newAssocVarDef)
	{
		assocVarDef = newAssocVarDef;
	}
}
