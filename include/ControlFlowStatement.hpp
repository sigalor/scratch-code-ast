#pragma once



#include <memory>

#include "Node.hpp"
#include "Statement.hpp"



namespace ast
{
	class ControlFlowStatement : public Statement
	{
		public:
			static const int									uniqueId = 0x00000411;
		
		private:
		
		protected:
			ControlFlowStatement(int newId);
			ControlFlowStatement(int newId, std::shared_ptr<Node> newParent);
		
		public:
			ControlFlowStatement();
			ControlFlowStatement(std::shared_ptr<Node> newParent);
	};
}
