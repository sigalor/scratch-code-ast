#pragma once



#include <memory>

#include "Node.hpp"
#include "Statement.hpp"



namespace ast
{
	class Value : public Statement
	{
		public:
			static const int									uniqueId = 0x00000311;
	
		private:
		
		protected:
			Value(int newId);
			Value(int newId, std::shared_ptr<Node> newParent);
		
		public:
			Value();
			Value(std::shared_ptr<Node> newParent);
	};
}
