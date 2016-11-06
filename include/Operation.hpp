#pragma once



#include <string>
#include <memory>

#include "Node.hpp"
#include "RValue.hpp"



namespace ast
{
	class Operation : public RValue
	{
		public:
			static const int									uniqueId = 0x00032311;
	
		private:
		
		protected:
			Operation(int newId);
			Operation(int newId, std::shared_ptr<Node> newParent);
		
		public:
			Operation();
			Operation(std::shared_ptr<Node> newParent);
	};
}
