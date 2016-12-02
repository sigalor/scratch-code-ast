/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/src/LoopControlStatement.cpp
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



#include "LoopControlStatement.hpp"



namespace ast
{
	const int LoopControlStatement::uniqueId = 0x00003411;

	LoopControlStatement::LoopControlStatement(int newId) : ControlFlowStatement(newId), statement(Lexer::ParsedLoopControlStatement::Invalid) { }
	LoopControlStatement::LoopControlStatement(int newId, std::shared_ptr<Node> newParent) : ControlFlowStatement(newId, newParent), statement(Lexer::ParsedLoopControlStatement::Invalid) { }
	LoopControlStatement::LoopControlStatement(int newId, std::shared_ptr<Node> newParent, Lexer::ParsedLoopControlStatement newStatement, std::shared_ptr<ControllableLoop> newTargetLoop) : ControlFlowStatement(newId, newParent), statement(newStatement), targetLoop(newTargetLoop) { }

	LoopControlStatement::LoopControlStatement() : ControlFlowStatement(uniqueId), statement(Lexer::ParsedLoopControlStatement::Invalid) { }
	LoopControlStatement::LoopControlStatement(std::shared_ptr<Node> newParent) : ControlFlowStatement(uniqueId, newParent), statement(Lexer::ParsedLoopControlStatement::Invalid) { }
	LoopControlStatement::LoopControlStatement(std::shared_ptr<Node> newParent, Lexer::ParsedLoopControlStatement newStatement, std::shared_ptr<ControllableLoop> newTargetLoop) : ControlFlowStatement(uniqueId, newParent), statement(newStatement), targetLoop(newTargetLoop) { }
	
	Lexer::ParsedLoopControlStatement LoopControlStatement::getStatement()
	{
		return statement;
	}
	
	std::shared_ptr<ControllableLoop> LoopControlStatement::getTargetLoop()
	{
		return targetLoop;
	}
	
	void LoopControlStatement::setStatement(Lexer::ParsedLoopControlStatement newStatement)
	{
		statement = newStatement;
	}
	
	void LoopControlStatement::setTargetLoop(std::shared_ptr<ControllableLoop> newTargetLoop)
	{
		targetLoop = newTargetLoop;
	}
}
