#pragma once



#include <memory>

#include "Node.hpp"
#include "Value.hpp"
#include "ControlFlowStatement.hpp"
#include "FunctionDefinition.hpp"



namespace ast
{
	class ReturnStatement : public ControlFlowStatement
	{
		public:
			static const int									uniqueId;
	
		private:
			std::shared_ptr<Value>								value;
			std::shared_ptr<FunctionDefinition>					targetFunc;
		
		protected:
			ReturnStatement(int newId);
			ReturnStatement(int newId, std::shared_ptr<Node> newParent);
			ReturnStatement(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<Value> newValue, std::shared_ptr<FunctionDefinition> newTargetFunc);
		
		public:
			ReturnStatement();
			ReturnStatement(std::shared_ptr<Node> newParent);
			ReturnStatement(std::shared_ptr<Node> newParent, std::shared_ptr<Value> newValue, std::shared_ptr<FunctionDefinition> newTargetFunc);
			std::shared_ptr<Value>								getValue();
			std::shared_ptr<FunctionDefinition>					getTargetFunc();
			void												setValue(std::shared_ptr<Value> newValue);
			void												setTargetFunc(std::shared_ptr<FunctionDefinition> newTargetFunc);
	};
}
