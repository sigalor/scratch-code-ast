#pragma once



#include <string>
#include <memory>

#include "Node.hpp"
#include "ControlFlowStatement.hpp"
#include "ControllableLoop.hpp"
#include "LexerTokenDefinitions.hpp"



namespace ast
{
	class LoopControlStatement : public ControlFlowStatement														//break, continue
	{
		public:
			static const int									uniqueId;
	
		private:
			Lexer::ParsedLoopControlStatement					statement;
			std::shared_ptr<ControllableLoop>					targetLoop;
		
		protected:
			LoopControlStatement(int newId);
			LoopControlStatement(int newId, std::shared_ptr<Node> newParent);
			LoopControlStatement(int newId, std::shared_ptr<Node> newParent, Lexer::ParsedLoopControlStatement newStatement, std::shared_ptr<ControllableLoop> newTargetLoop);
		
		public:
			LoopControlStatement();
			LoopControlStatement(std::shared_ptr<Node> newParent);
			LoopControlStatement(std::shared_ptr<Node> newParent, Lexer::ParsedLoopControlStatement newStatement, std::shared_ptr<ControllableLoop> newTargetLoop);
			Lexer::ParsedLoopControlStatement					getStatement();
			std::shared_ptr<ControllableLoop>					getTargetLoop();
			void												setStatement(Lexer::ParsedLoopControlStatement newStatement);
			void												setTargetLoop(std::shared_ptr<ControllableLoop> newTargetLoop);
	};
}
