#pragma once



#include <memory>

#include "Node.hpp"
#include "Value.hpp"



namespace ast
{
	class RValue : public Value
	{
		public:
			static const int									uniqueId = 0x00002311;
	
		private:
		
		protected:
			RValue(int newId);
			RValue(int newId, std::shared_ptr<Node> newParent);
		
		public:
			RValue();
			RValue(std::shared_ptr<Node> newParent);
	};
}
