#include "FunctionDefinition.hpp"



namespace ast
{
	FunctionDefinition::FunctionDefinition(int newId) : Statement(newId), returnType(Lexer::ParsedVariableType::Invalid) { }
	FunctionDefinition::FunctionDefinition(int newId, std::shared_ptr<Node> newParent) : Statement(newId, newParent), returnType(Lexer::ParsedVariableType::Invalid) { }
	FunctionDefinition::FunctionDefinition(int newId, std::shared_ptr<Node> newParent, Lexer::ParsedVariableType newReturnType, const std::string& newName, std::shared_ptr<VariableDefinitionList> newArgs, std::shared_ptr<StatementList> newBody) : Statement(newId, newParent), returnType(newReturnType), name(newName), args(newArgs), body(newBody) { }

	FunctionDefinition::FunctionDefinition() : Statement(uniqueId), returnType(Lexer::ParsedVariableType::Invalid) { }
	FunctionDefinition::FunctionDefinition(std::shared_ptr<Node> newParent) : Statement(uniqueId, newParent), returnType(Lexer::ParsedVariableType::Invalid) { }
	FunctionDefinition::FunctionDefinition(std::shared_ptr<Node> newParent, Lexer::ParsedVariableType newReturnType, const std::string& newName, std::shared_ptr<VariableDefinitionList> newArgs, std::shared_ptr<StatementList> newBody) : Statement(uniqueId, newParent), returnType(newReturnType), name(newName), args(newArgs), body(newBody) { }
	
	Lexer::ParsedVariableType FunctionDefinition::getReturnType()
	{
		return returnType;
	}
	
	const std::string& FunctionDefinition::getName()
	{
		return name;
	}
	
	std::shared_ptr<VariableDefinitionList> FunctionDefinition::getArgs()
	{
		return args;
	}
	
	std::shared_ptr<StatementList> FunctionDefinition::getBody()
	{
		return body;
	}
	
	void FunctionDefinition::setReturnType(Lexer::ParsedVariableType newReturnType)
	{
		returnType = newReturnType;
	}
	
	void FunctionDefinition::setName(const std::string& newName)
	{
		name = newName;
	}
	
	void FunctionDefinition::setArgs(std::shared_ptr<VariableDefinitionList> newArgs)
	{
		args = newArgs;
	}
	
	void FunctionDefinition::setBody(std::shared_ptr<StatementList> newBody)
	{
		body = newBody;
	}
}
