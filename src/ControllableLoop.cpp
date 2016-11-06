#include "ControllableLoop.hpp"



namespace ast
{
	ControllableLoop::ControllableLoop(int newId) : ControlFlowStatement(newId) { }
	ControllableLoop::ControllableLoop(int newId, std::shared_ptr<Node> newParent) : ControlFlowStatement(newId, newParent) { }

	ControllableLoop::ControllableLoop() : ControlFlowStatement(uniqueId) { }
	ControllableLoop::ControllableLoop(std::shared_ptr<Node> newParent) : ControlFlowStatement(uniqueId, newParent) { }
}
