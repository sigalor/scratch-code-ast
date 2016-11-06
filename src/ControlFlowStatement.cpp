#include "ControlFlowStatement.hpp"



namespace ast
{
	ControlFlowStatement::ControlFlowStatement(int newId) : Statement(newId) { }
	ControlFlowStatement::ControlFlowStatement(int newId, std::shared_ptr<Node> newParent) : Statement(newId, newParent) { }

	ControlFlowStatement::ControlFlowStatement() : Statement(uniqueId) { }
	ControlFlowStatement::ControlFlowStatement(std::shared_ptr<Node> newParent) : Statement(uniqueId, newParent) { }
}
