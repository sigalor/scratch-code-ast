#include "LoopControlStatement.hpp"



namespace ast
{
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
