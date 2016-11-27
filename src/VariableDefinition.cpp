#include "VariableDefinition.hpp"



namespace ast
{
	const int VariableDefinition::uniqueId = 0x00000111;

	VariableDefinition::VariableDefinition(int newId) : Statement(newId), type(Lexer::ParsedVariableType::Invalid) { }
	VariableDefinition::VariableDefinition(int newId, std::shared_ptr<Node> newParent) : Statement(newId, newParent), type(Lexer::ParsedVariableType::Invalid) { }
	VariableDefinition::VariableDefinition(int newId, std::shared_ptr<Node> newParent, Lexer::ParsedVariableType newType, const std::string& newName) : Statement(newId, newParent), type(newType), name(newName) { }

	VariableDefinition::VariableDefinition() : Statement(uniqueId), type(Lexer::ParsedVariableType::Invalid) { }
	VariableDefinition::VariableDefinition(std::shared_ptr<Node> newParent) : Statement(uniqueId, newParent), type(Lexer::ParsedVariableType::Invalid) { }
	VariableDefinition::VariableDefinition(std::shared_ptr<Node> newParent, Lexer::ParsedVariableType newType, const std::string& newName) : Statement(uniqueId, newParent), type(newType), name(newName) { }
	
	Lexer::ParsedVariableType VariableDefinition::getType()
	{
		return type;
	}
	
	std::string& VariableDefinition::getName()
	{
		return name;
	}
	
	void VariableDefinition::setType(Lexer::ParsedVariableType newType)
	{
		type = newType;
	}
	
	void VariableDefinition::setName(const std::string& newName)
	{
		name = newName;
	}
}
