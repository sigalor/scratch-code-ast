#include "FunctionCall.hpp"



namespace ast
{
	FunctionCall::FunctionCall(int newId) : RValue(newId) { }
	FunctionCall::FunctionCall(int newId, std::shared_ptr<Node> newParent) : RValue(newId, newParent) { }
	FunctionCall::FunctionCall(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<FunctionDefinition> newAssocFunc, std::shared_ptr<ValueList> newArgs) : RValue(newId, newParent), assocFunc(newAssocFunc), args(newArgs) { }

	FunctionCall::FunctionCall() : RValue(uniqueId) { }
	FunctionCall::FunctionCall(std::shared_ptr<Node> newParent) : RValue(uniqueId, newParent) { }
	FunctionCall::FunctionCall(std::shared_ptr<Node> newParent, std::shared_ptr<FunctionDefinition> newAssocFunc, std::shared_ptr<ValueList> newArgs) : RValue(uniqueId, newParent), assocFunc(newAssocFunc), args(newArgs) { }
	
	std::shared_ptr<FunctionDefinition> FunctionCall::getAssocFunc()
	{
		return assocFunc;
	}
	
	std::shared_ptr<ValueList> FunctionCall::getArgs()
	{
		return args;
	}
	
	void FunctionCall::setAssocFunc(std::shared_ptr<FunctionDefinition> newAssocFunc)
	{
		assocFunc = newAssocFunc;
	}
	
	void FunctionCall::setArgs(std::shared_ptr<ValueList> newArgs)
	{
		args = newArgs;
	}
}
