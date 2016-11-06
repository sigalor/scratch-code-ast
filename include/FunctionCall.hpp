#pragma once



#include <memory>

#include "Node.hpp"
#include "FunctionDefinition.hpp"
#include "RValue.hpp"
#include "ValueList.hpp"



namespace ast
{
	class FunctionCall : public RValue
	{
		public:
			static const int									uniqueId = 0x00022311;
	
		private:
			std::shared_ptr<FunctionDefinition>					assocFunc;
			std::shared_ptr<ValueList>							args;
		
		protected:
			FunctionCall(int newId);
			FunctionCall(int newId, std::shared_ptr<Node> newParent);
			FunctionCall(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<FunctionDefinition> newAssocFunc, std::shared_ptr<ValueList> newArgs);
		
		public:
			FunctionCall();
			FunctionCall(std::shared_ptr<Node> newParent);
			FunctionCall(std::shared_ptr<Node> newParent, std::shared_ptr<FunctionDefinition> newAssocFunc, std::shared_ptr<ValueList> newArgs);
			std::shared_ptr<FunctionDefinition>					getAssocFunc();
			std::shared_ptr<ValueList>							getArgs();
			void												setAssocFunc(std::shared_ptr<FunctionDefinition> newAssocFunc);
			void												setArgs(std::shared_ptr<ValueList> newArgs);
	};
}
