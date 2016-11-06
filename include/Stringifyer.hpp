#pragma once



#include <iomanip>
#include <string>
#include <sstream>
#include <memory>

#include "LexerTokenDefinitions.hpp"
#include "Node.hpp"
#include "Statement.hpp"
#include "VariableDefinition.hpp"
#include "FunctionDefinition.hpp"
#include "Value.hpp"
#include "LValue.hpp"
#include "RValue.hpp"
#include "RValueValue.hpp"
#include "FunctionCall.hpp"
#include "Operation.hpp"
#include "UnaryOperation.hpp"
#include "BinaryOperation.hpp"
#include "ControlFlowStatement.hpp"
#include "Conditional.hpp"
#include "ControllableLoop.hpp"
#include "ForLoop.hpp"
#include "WhileLoop.hpp"
#include "LoopControlStatement.hpp"
#include "ReturnStatement.hpp"
#include "StatementList.hpp"
#include "VariableDefinitionList.hpp"
#include "ValueList.hpp"



namespace ast
{
	template<typename T>
	std::string pointerToString(T* addr)																			//from http://stackoverflow.com/a/7850160
	{
		if(addr == nullptr)
			return "(nullptr)";

		std::stringstream ss;
		ss << addr;
		return ss.str();
	}

	std::string stringify(std::shared_ptr<Node> obj, std::size_t indent=0, bool indentFirstLine=true, bool newlineAfterLastLine=true, bool fullOutput=true);
}
