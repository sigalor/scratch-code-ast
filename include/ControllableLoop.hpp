#pragma once



#include <memory>

#include "Node.hpp"
#include "ControlFlowStatement.hpp"



namespace ast
{
	class ControllableLoop : public ControlFlowStatement															//a ControllableLoop lets itself control by a LoopControlStatement
	{
		public:
			static const int									uniqueId;
		
		private:
		
		protected:
			ControllableLoop(int newId);
			ControllableLoop(int newId, std::shared_ptr<Node> newParent);
		
		public:
			ControllableLoop();
			ControllableLoop(std::shared_ptr<Node> newParent);
	};
}
