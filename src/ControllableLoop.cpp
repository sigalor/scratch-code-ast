#include "ControllableLoop.hpp"



namespace ast
{
	const int ControllableLoop::uniqueId = 0x00002411;

	ControllableLoop::ControllableLoop(int newId) : ControlFlowStatement(newId) { }
	ControllableLoop::ControllableLoop(int newId, std::shared_ptr<Node> newParent) : ControlFlowStatement(newId, newParent) { }

	ControllableLoop::ControllableLoop() : ControlFlowStatement(uniqueId) { }
	ControllableLoop::ControllableLoop(std::shared_ptr<Node> newParent) : ControlFlowStatement(uniqueId, newParent) { }
}
