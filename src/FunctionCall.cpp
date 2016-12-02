/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/src/FunctionCall.cpp
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



#include "FunctionCall.hpp"



namespace ast
{
	const int FunctionCall::uniqueId = 0x00022311;

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
