#pragma once



#include <memory>

#include "Node.hpp"



namespace ast
{
	class Statement : public Node
	{
		public:
			static const int									uniqueId = 0x00000011;
	
		private:
		
		protected:
			Statement(int newId);
			Statement(int newId, std::shared_ptr<Node> newParent);
		
		public:
			Statement();
			Statement(std::shared_ptr<Node> newParent);
	};
}

