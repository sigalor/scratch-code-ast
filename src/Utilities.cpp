/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/src/Utilities.cpp
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */



#include "Utilities.hpp"



namespace ast
{
	void doRecursively(std::shared_ptr<Node> obj, RecursiveFunctionsType& funcs)
	{
		if(obj == nullptr)
			return;
	
		if(doFunctionForType<BinaryOperation>(obj, funcs))
		{
			auto real = std::static_pointer_cast<BinaryOperation>(obj);
			doRecursively(real->getLhs(), funcs);
			doRecursively(real->getRhs(), funcs);
		}
		else if(doFunctionForType<Conditional>(obj, funcs))
		{
			auto real = std::static_pointer_cast<Conditional>(obj);
			doRecursively(real->getCondition(), funcs);
			doRecursively(real->getConsequenceBody(), funcs);
			doRecursively(real->getAlternativeBody(), funcs);
		}
		else if(doFunctionForType<ControlFlowStatement>(obj, funcs)) { }
		else if(doFunctionForType<ControllableLoop>(obj, funcs)) { }
		else if(doFunctionForType<ForLoop>(obj, funcs))
		{
			auto real = std::static_pointer_cast<ForLoop>(obj);
			doRecursively(real->getInitialization(), funcs);
			doRecursively(real->getCondition(), funcs);
			doRecursively(real->getAfterthought(), funcs);
			doRecursively(real->getBody(), funcs);
		}
		else if(doFunctionForType<FunctionCall>(obj, funcs))														//"real->getAssocFunc()" is not used here to prevent infinite loops!
		{
			auto real = std::static_pointer_cast<FunctionCall>(obj);
			doRecursively(real->getArgs(), funcs);
		}
		else if(doFunctionForType<FunctionDefinition>(obj, funcs))
		{
			auto real = std::static_pointer_cast<FunctionDefinition>(obj);
			doRecursively(real->getArgs(), funcs);
			doRecursively(real->getBody(), funcs);
		}
		else if(doFunctionForType<LoopControlStatement>(obj, funcs)) { }											//"real->getTargetLoop()" is ignored for the same reason
		else if(doFunctionForType<LValue>(obj, funcs)) { }															//"real->getAssocVarDef()" as well
		else if(doFunctionForType<Node>(obj, funcs)) { }
		else if(doFunctionForType<Operation>(obj, funcs)) { }
		else if(doFunctionForType<ReturnStatement>(obj, funcs))														//"real->getTargetFunc()" as well
		{
			auto real = std::static_pointer_cast<ReturnStatement>(obj);
			doRecursively(real->getValue(), funcs);
		}
		else if(doFunctionForType<RValue>(obj, funcs)) { }
		else if(doFunctionForType<RValueValue>(obj, funcs)) { }
		else if(doFunctionForType<Statement>(obj, funcs)) { }
		else if(doFunctionForType<StatementList>(obj, funcs))
		{
			auto real = std::static_pointer_cast<StatementList>(obj);
			for(auto s : real->getStatements())
				doRecursively(s, funcs);
		}
		else if(doFunctionForType<UnaryOperation>(obj, funcs))
		{
			auto real = std::static_pointer_cast<UnaryOperation>(obj);
			doRecursively(real->getValue(), funcs);
		}
		else if(doFunctionForType<Value>(obj, funcs)) { }
		else if(doFunctionForType<ValueList>(obj, funcs))
		{
			auto real = std::static_pointer_cast<ValueList>(obj);
			for(auto v : real->getValues())
				doRecursively(v, funcs);
		}
		else if(doFunctionForType<VariableDefinition>(obj, funcs)) { }
		else if(doFunctionForType<VariableDefinitionList>(obj, funcs))
		{
			auto real = std::static_pointer_cast<VariableDefinitionList>(obj);
			for(auto vd : real->getVarDefs())
				doRecursively(vd, funcs);
		}
		else if(doFunctionForType<WhileLoop>(obj, funcs))
		{
			auto real = std::static_pointer_cast<WhileLoop>(obj);
			doRecursively(real->getCondition(), funcs);
			doRecursively(real->getBody(), funcs);
		}
	}
	
	void optimize(std::shared_ptr<Node> obj)
	{
		//TODO
	}

	std::string stringify(std::shared_ptr<Node> obj, std::size_t indent, bool indentFirstLine, bool newlineAfterLastLine, bool fullOutput)
	{
		std::string ret;
		std::string indentStr0(indent, '\t');
		std::string indentStr1(indent+1, '\t');
		std::string indentStr2(indent+2, '\t');
		std::string fl(indentFirstLine ? indentStr0 : "");
		std::string nl(newlineAfterLastLine ? "\n" : "");
		
		if(obj == nullptr)
			return fl + "(nullptr)" + nl;
		
		ret = fl + " (" + pointerToString(obj.get()) + ")";
		if(fullOutput)
			ret += "\n" + indentStr0 + "{\n" +
				   indentStr1 + "parent = " + pointerToString(obj->getParent().get());
		else
			ret += " { ... }" + nl;
		

		if(obj->getId() == BinaryOperation::uniqueId)
		{
			std::shared_ptr<BinaryOperation> objReal(std::static_pointer_cast<BinaryOperation>(obj));
			ret.insert(fl.size(), "BinaryOperation");
			if(fullOutput)
				ret += ",\n" +
					   indentStr1 + "lhs = " + stringify(objReal->getLhs(), indent+1, false, false) + ",\n" +
					   indentStr1 + "operation = ParsedBinaryOperation::" + Lexer::getStringVerbose(objReal->getOperation()) + ",\n" +
					   indentStr1 + "rhs = " + stringify(objReal->getRhs(), indent+1, false, true);
		}
		else if(obj->getId() == Conditional::uniqueId)
		{
			std::shared_ptr<Conditional> objReal(std::static_pointer_cast<Conditional>(obj));
			ret.insert(fl.size(), "Conditional");
			if(fullOutput)
				ret += ",\n" +
					   indentStr1 + "condition = " + stringify(objReal->getCondition(), indent+1, false, false) + ",\n" +
					   indentStr1 + "consequenceBody = " + stringify(objReal->getConsequenceBody(), indent+1, false, false) + ",\n" +
					   indentStr1 + "alternativeBody = " + stringify(objReal->getAlternativeBody(), indent+1, false, true);
		}
		else if(obj->getId() == ControlFlowStatement::uniqueId)
		{
			ret.insert(fl.size(), "ControlFlowStatement");
			if(fullOutput)
				ret += "\n";
		}
		else if(obj->getId() == ControllableLoop::uniqueId)
		{
			ret.insert(fl.size(), "ControllableLoop");
			if(fullOutput)
				ret += "\n";
		}
		else if(obj->getId() == ForLoop::uniqueId)
		{
			std::shared_ptr<ForLoop> objReal(std::static_pointer_cast<ForLoop>(obj));
			ret.insert(fl.size(), "ForLoop");
			if(fullOutput)
				ret += ",\n" +
					   indentStr1 + "initialization = " + stringify(objReal->getInitialization(), indent+1, false, false) + ",\n" +
					   indentStr1 + "condition = " + stringify(objReal->getCondition(), indent+1, false, false) + ",\n" +
					   indentStr1 + "afterthought = " + stringify(objReal->getAfterthought(), indent+1, false, false) + ",\n" +
					   indentStr1 + "body = " + stringify(objReal->getBody(), indent+1, false, true);
		}
		else if(obj->getId() == FunctionCall::uniqueId)
		{
			std::shared_ptr<FunctionCall> objReal(std::static_pointer_cast<FunctionCall>(obj));
			ret.insert(fl.size(), "FunctionCall");
			if(fullOutput)
				ret += ",\n" +
					   indentStr1 + "assocFunc = " + stringify(objReal->getAssocFunc(), indent+1, false, false, false) + ",\n" +
					   indentStr1 + "args = " + stringify(objReal->getArgs(), indent+1, false, true);
		}
		else if(obj->getId() == FunctionDefinition::uniqueId)
		{
			std::shared_ptr<FunctionDefinition> objReal(std::static_pointer_cast<FunctionDefinition>(obj));
			ret.insert(fl.size(), "FunctionDefinition");
			if(fullOutput)
				ret += ",\n" +
					   indentStr1 + "returnType = ParsedVariableType::" + Lexer::getStringVerbose(objReal->getReturnType()) + ",\n" +
					   indentStr1 + "name = \"" + objReal->getName() + "\",\n" +
					   indentStr1 + "args = " + stringify(objReal->getArgs(), indent+1, false, false) + ",\n" +
					   indentStr1 + "body = " + stringify(objReal->getBody(), indent+1, false, true);
		}
		else if(obj->getId() == LoopControlStatement::uniqueId)
		{
			std::shared_ptr<LoopControlStatement> objReal(std::static_pointer_cast<LoopControlStatement>(obj));
			ret.insert(fl.size(), "LoopControlStatement");
			if(fullOutput)
				ret += ",\n" +
					   indentStr1 + "statement = ParsedLoopControlStatement::" + Lexer::getStringVerbose(objReal->getStatement()) + ",\n" +
					   indentStr1 + "targetLoop = " + stringify(objReal->getTargetLoop(), indent+1, false, true, false);
		}
		else if(obj->getId() == LValue::uniqueId)
		{
			std::shared_ptr<LValue> objReal(std::static_pointer_cast<LValue>(obj));
			ret.insert(fl.size(), "LValue");
			if(fullOutput)
				ret += ",\n" +
					   indentStr1 + "assocVarDef = " + stringify(objReal->getAssocVarDef(), indent+1, false, true);
		}
		else if(obj->getId() == Node::uniqueId)
		{
			ret.insert(fl.size(), "Node");
			if(fullOutput)
				ret += "\n";
		}
		else if(obj->getId() == Operation::uniqueId)
		{
			ret.insert(fl.size(), "Operation");
			if(fullOutput)
				ret += "\n";
		}
		else if(obj->getId() == ReturnStatement::uniqueId)
		{
			std::shared_ptr<ReturnStatement> objReal(std::static_pointer_cast<ReturnStatement>(obj));
			ret.insert(fl.size(), "ReturnStatement");
			if(fullOutput)
				ret += ",\n" +
					   indentStr1 + "value = " + stringify(objReal->getValue(), indent+1, false, false) + ",\n" +
					   indentStr1 + "targetFunc = " + stringify(objReal->getTargetFunc(), indent+1, false, true, false);
		}
		else if(obj->getId() == RValue::uniqueId)
		{
			ret.insert(fl.size(), "RValue");
			if(fullOutput)
				ret += "\n";
		}
		else if(obj->getId() == RValueValue::uniqueId)
		{
			std::shared_ptr<RValueValue> objReal(std::static_pointer_cast<RValueValue>(obj));
			if(fullOutput)
			{
				ret.insert(fl.size(), "RValueValue");
				ret += ",\n" +
					   indentStr1 + "type = ParsedVariableType::" + Lexer::getStringVerbose(objReal->getType()) + ",\n" +
					   indentStr1 + "value = " + objReal->getValueString() + "\n";
			}
		}
		else if(obj->getId() == Statement::uniqueId)
		{
			ret.insert(fl.size(), "Statement");
			if(fullOutput)
				ret += "\n";
		}
		else if(obj->getId() == StatementList::uniqueId)
		{
			std::shared_ptr<StatementList> objReal(std::static_pointer_cast<StatementList>(obj));
			ret.insert(fl.size(), "StatementList");
			if(fullOutput)
			{
				ret += ",\n" +
					   indentStr1 + "statements = std::vector of size " + std::to_string(objReal->getStatements().size()) + "\n" +
					   indentStr1 + "[\n";
				for(auto it = objReal->getStatements().begin(); it != objReal->getStatements().end(); ++it)
					ret += stringify(*it, indent+2, true, false) + (it+1 != objReal->getStatements().end() ? "," : "") + "\n";
				ret += indentStr1 + "]\n";
			}
		}
		else if(obj->getId() == UnaryOperation::uniqueId)
		{
			std::shared_ptr<UnaryOperation> objReal(std::static_pointer_cast<UnaryOperation>(obj));
			ret.insert(fl.size(), "UnaryOperation");
			if(fullOutput)
				ret += ",\n" +
					   indentStr1 + "operation = ParsedUnaryOperation::" + Lexer::getStringVerbose(objReal->getOperation()) + ",\n" +
					   indentStr1 + "value = " + stringify(objReal->getValue(), indent+1, false, true);
		}
		else if(obj->getId() == Value::uniqueId)
		{
			ret.insert(fl.size(), "Value");
			if(fullOutput)
				ret += "\n";
		}
		else if(obj->getId() == ValueList::uniqueId)
		{
			std::shared_ptr<ValueList> objReal(std::static_pointer_cast<ValueList>(obj));
			ret.insert(fl.size(), "ValueList");
			if(fullOutput)
			{
				ret += ",\n" +
					   indentStr1 + "values = std::vector of size " + std::to_string(objReal->getValues().size()) + "\n" +
					   indentStr1 + "[\n";
				for(auto it = objReal->getValues().begin(); it != objReal->getValues().end(); ++it)
					  ret += stringify(*it, indent+2, true, false) + (it+1 != objReal->getValues().end() ? "," : "") + "\n";
				ret += indentStr1 + "]\n";
			}
		}
		else if(obj->getId() == VariableDefinition::uniqueId)
		{
			std::shared_ptr<VariableDefinition> objReal(std::static_pointer_cast<VariableDefinition>(obj));
			ret.insert(fl.size(), "VariableDefinition");
			if(fullOutput)
				ret += ",\n" +
					   indentStr1 + "type = ParsedVariableType::" + Lexer::getStringVerbose(objReal->getType()) + ",\n" +
					   indentStr1 + "name = \"" + objReal->getName() + "\"\n";
		}
		else if(obj->getId() == VariableDefinitionList::uniqueId)
		{
			std::shared_ptr<VariableDefinitionList> objReal(std::static_pointer_cast<VariableDefinitionList>(obj));
			ret.insert(fl.size(), "VariableDefinitionList");
			if(fullOutput)
			{
				ret += ",\n" +
					   indentStr1 + "varDefs = std::vector of size " + std::to_string(objReal->getVarDefs().size()) + "\n" +
					   indentStr1 + "[\n";
				for(auto it = objReal->getVarDefs().begin(); it != objReal->getVarDefs().end(); ++it)
					  ret += stringify(*it, indent+2, true, false) + (it+1 != objReal->getVarDefs().end() ? "," : "") + "\n";
				ret += indentStr1 + "]\n";
			}
		}
		else if(obj->getId() == WhileLoop::uniqueId)
		{
			std::shared_ptr<WhileLoop> objReal(std::static_pointer_cast<WhileLoop>(obj));
			ret.insert(fl.size(), "WhileLoop");
			if(fullOutput)
				ret += ",\n" +
					   indentStr1 + "condition = " + stringify(objReal->getCondition(), indent+1, false, false) + ",\n" +
					   indentStr1 + "body = " + stringify(objReal->getBody(), indent+1, false, true);
		}
		else
			return (fl + "(invalid id: " + std::to_string(obj->getId()) + ")" + nl);
		
		if(!fullOutput)
			return ret;
		ret += indentStr0 + "}" + nl;
		
		return ret;
	}
}
