/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/include/LoopControlStatement.hpp
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
