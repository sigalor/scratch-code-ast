#pragma once



#include <memory>

#include "Node.hpp"
#include "Value.hpp"
#include "ControllableLoop.hpp"
#include "StatementList.hpp"



namespace ast
{
	class WhileLoop : public ControllableLoop
	{
		public:
			static const int									uniqueId = 0x00022411;
	
		private:
			std::shared_ptr<Value>								condition;
			std::shared_ptr<StatementList>						body;
		
		protected:
			WhileLoop(int newId);
			WhileLoop(int newId, std::shared_ptr<Node> newParent);
			WhileLoop(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<Value> newCondition, std::shared_ptr<StatementList> newBody);
		
		public:
			WhileLoop();
			WhileLoop(std::shared_ptr<Node> newParent);
			WhileLoop(std::shared_ptr<Node> newParent, std::shared_ptr<Value> newCondition, std::shared_ptr<StatementList> newBody);
			std::shared_ptr<Value>								getCondition();
			std::shared_ptr<StatementList>						getBody();
			void												setCondition(std::shared_ptr<Value> newCondition);
			void												setBody(std::shared_ptr<StatementList> newBody);
	};
}
