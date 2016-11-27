#pragma once



#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <memory>
#include <functional>
#include <unordered_map>
#include <boost/variant.hpp>

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
	std::string toString(T val)
	{
		std::stringstream ss;
		ss << val;
		return ss.str();
	}
	
	template<typename T>
	std::string pointerToString(T* addr)																			//from http://stackoverflow.com/a/7850160
	{
		return ((addr == nullptr) ? "(nullptr)" : toString(addr));
	}
	
	using RecursiveFunctionsType = std::unordered_map<int, std::function<void(std::shared_ptr<Node>)>>;
	
	template<typename T>
	typename std::enable_if_t<std::is_base_of<Node, T>::value, bool>
	doFunctionForType(std::shared_ptr<Node> obj, RecursiveFunctionsType& funcs)
	{
		if(obj->isA<T>())
		{
			if(funcs.count(T::uniqueId))																			//count from http://stackoverflow.com/a/11765524
				funcs[T::uniqueId](obj);
			return true;
		}
		return false;
	}

	void			doRecursively(std::shared_ptr<Node> obj, RecursiveFunctionsType& funcs);
	std::string		stringify(std::shared_ptr<Node> obj, std::size_t indent=0, bool indentFirstLine=true, bool newlineAfterLastLine=true, bool fullOutput=true);
}
