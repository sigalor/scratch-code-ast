#pragma once



#include <vector>
#include <memory>

#include "Node.hpp"
#include "Value.hpp"
#include "ControlFlowStatement.hpp"
#include "StatementList.hpp"



namespace ast
{
	class Conditional : public ControlFlowStatement
	{
		public:
			static const int									uniqueId = 0x00001411;
	
		private:
			std::vector<std::shared_ptr<Value>>					conditions;
			std::vector<std::shared_ptr<StatementList>>			consequenceBodies;
			std::shared_ptr<StatementList>						alternativeBody;
		
		protected:
			Conditional(int newId);
			Conditional(int newId, std::shared_ptr<Node> newParent);
			Conditional(int newId, std::shared_ptr<Node> newParent, std::vector<std::shared_ptr<Value>> newConditions, std::vector<std::shared_ptr<StatementList>> newConsequenceBodies, std::shared_ptr<StatementList> newAlternativeBody);
		
		public:
			Conditional();
			Conditional(std::shared_ptr<Node> newParent);
			Conditional(std::shared_ptr<Node> newParent, std::vector<std::shared_ptr<Value>> newConditions, std::vector<std::shared_ptr<StatementList>> newConsequenceBodies, std::shared_ptr<StatementList> newAlternativeBody);
			std::vector<std::shared_ptr<Value>>&				getConditions();
			std::vector<std::shared_ptr<StatementList>>&		getConsequenceBodies();
			std::shared_ptr<StatementList>						getAlternativeBody();
			void												addCondition(std::shared_ptr<Value> newCondition);
			void												addConsequenceBody(std::shared_ptr<StatementList> newConsequenceBody);
			void												setAlternativeBody(std::shared_ptr<StatementList> newAlternativeBody);
	};
}
