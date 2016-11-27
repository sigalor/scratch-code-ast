#pragma once



#include <vector>
#include <memory>

#include "Node.hpp"
#include "Value.hpp"



namespace ast
{
	class ValueList : public Node																				//needed from FunctionCall
	{
		public:
			static const int									uniqueId;
	
		private:
			std::vector<std::shared_ptr<Value>>					values;
		
		protected:
			ValueList(int newId);
			ValueList(int newId, std::shared_ptr<Node> newParent);
			ValueList(int newId, std::shared_ptr<Node> newParent, const std::vector<std::shared_ptr<Value>>& newValues);
		
		public:
			ValueList();
			ValueList(std::shared_ptr<Node> newParent);
			ValueList(std::shared_ptr<Node> newParent, const std::vector<std::shared_ptr<Value>>& newValues);
			std::vector<std::shared_ptr<Value>>&				getValues();
			void												addValue(std::shared_ptr<Value> newVal);
	};
}
