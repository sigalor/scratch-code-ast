#pragma once



#include <memory>

#include "Node.hpp"
#include "VariableDefinition.hpp"
#include "Value.hpp"



namespace ast
{
	class LValue : public Value
	{
		public:
			static const int									uniqueId = 0x00001311;
	
		private:
			std::shared_ptr<VariableDefinition>					assocVarDef;
		
		protected:
			LValue(int newId);
			LValue(int newId, std::shared_ptr<Node> newParent);
			LValue(int newId, std::shared_ptr<Node> newParent, std::shared_ptr<VariableDefinition> newAssocVarDef);
		
		public:
			LValue();
			LValue(std::shared_ptr<Node> newParent);
			LValue(std::shared_ptr<Node> newParent, std::shared_ptr<VariableDefinition> newAssocVarDef);
			std::shared_ptr<VariableDefinition>					getAssocVarDef();
			void												setAssocVarDef(std::shared_ptr<VariableDefinition> newAssocVarDef);
	};
}
