#include "ControlFlowStatement.hpp"



namespace ast
{
	const int ControlFlowStatement::uniqueId = 0x00000411;

	ControlFlowStatement::ControlFlowStatement(int newId) : Statement(newId) { }
	ControlFlowStatement::ControlFlowStatement(int newId, std::shared_ptr<Node> newParent) : Statement(newId, newParent) { }

	ControlFlowStatement::ControlFlowStatement() : Statement(uniqueId) { }
	ControlFlowStatement::ControlFlowStatement(std::shared_ptr<Node> newParent) : Statement(uniqueId, newParent) { }
}
