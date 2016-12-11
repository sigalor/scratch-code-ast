/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/src/WhileLoop.cpp
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



#include <ast/WhileLoop.hpp>



namespace ast
{
	const int WhileLoop::uniqueId = 0x00022411;

	WhileLoop::WhileLoop(int newId) : ControllableLoop(newId) { }
	WhileLoop::WhileLoop(int newId, std::shared_ptr<Node> newParent) : ControllableLoop(newId, newParent) { }
	WhileLoop::WhileLoop(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<Value> newCondition, std::shared_ptr<StatementList> newBody) : ControllableLoop(newId, newParent), condition(newCondition), body(newBody) { }

	WhileLoop::WhileLoop() : ControllableLoop(uniqueId) { }
	WhileLoop::WhileLoop(std::shared_ptr<Node> newParent) : ControllableLoop(uniqueId, newParent) { }
	WhileLoop::WhileLoop(std::shared_ptr<Node> newParent, std::shared_ptr<Value> newCondition, std::shared_ptr<StatementList> newBody) : ControllableLoop(uniqueId, newParent), condition(newCondition), body(newBody) { }
	
	std::shared_ptr<Value> WhileLoop::getCondition()
	{
		return condition;
	}
	
	std::shared_ptr<StatementList> WhileLoop::getBody()
	{
		return body;
	}
	
	void WhileLoop::setCondition(std::shared_ptr<Value> newCondition)
	{
		condition = newCondition;
	}
	
	void WhileLoop::setBody(std::shared_ptr<StatementList> newBody)
	{
		body = newBody;
	}
}
