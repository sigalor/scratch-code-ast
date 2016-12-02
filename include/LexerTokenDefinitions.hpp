/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/include/LexerTokenDefinitions.hpp
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



#pragma once



#include <type_traits>
#include <string>


namespace ast
{
	namespace Lexer
	{
		/*
		* PRECEDENCE (extracted from http://en.cppreference.com/w/c/language/operator_precedence):
		*  1. ++ --				PostfixIncrement/PostfixDecrement		left-to-right			rvalue						all following unary
		*  2. ++ --				PrefixIncrement/PrefixDecrement			right-to-left			lvalue
		*     + -				UnaryPlus/UnaryMinus											all following rvalue
		*     ! ~				LogicalNot/BitwiseNot
		*     (type)			Typecast
		*     sizeof			Sizeof
		*  3. * / %				Multiply/Divide/Modulo					left-to-right										all following binary
		*  4. + -				Add/Subtract
		*  5. << >>				BitshiftLeft/BitshiftRight
		*  6. < <=				LessThan/LessThanOrEqual
		*     > >=				GreaterThan/GreaterThanOrEqual
		*  7. == !=				Equal/NotEqual
		*  8. &					BitwiseAnd
		*  9. ^					BitwiseXor
		* 10. |					BitwiseOr
		* 11. &&				LogicalAnd
		* 12. ||				LogicalOr
		* 13. =					Assignment								right-to-left			all following lvalue
		*     += -=				AddAssignment/SubtractAssignment
		*     *= /= %=			MultiplyAssignment/DivideAssignment/ModuloAssignment
		*     <<= >>=			BitshiftLeftAssignment/BitshiftRightAssignment
		*     &= ^= |=			BitwiseAndAssignment/BitwiseXorAssignment/BitwiseOrAssignment
		*/
	
		using UnderlyingTokenType = int;
		
		enum class ParsedVariableType : UnderlyingTokenType
		{
			Invalid = -1,
			Void,
			Bool,
			Int,
			Real,
			String
		};

		enum class ParsedUnaryOperation : UnderlyingTokenType
		{
			Invalid = -1,
			LogicalNot,
			BitwiseNot,
			PrefixIncrement,
			PrefixDecrement,
			PostfixIncrement,
			PostfixDecrement,
			UnaryPlus,
			UnaryMinus,
			TypecastBool,
			TypecastInt,
			TypecastReal,
			TypecastString
		};

		enum class ParsedBinaryOperation : UnderlyingTokenType
		{
			Invalid = -1,
			Add,
			Subtract,
			Multiply,
			Divide,
			Modulo,
			BitwiseAnd,
			BitwiseOr,
			BitwiseXor,
			BitshiftLeft,
			BitshiftRight,
			Assignment,
			AddAssignment,
			SubtractAssignment,
			MultiplyAssignment,
			DivideAssignment,
			ModuloAssignment,
			BitwiseAndAssignment,
			BitwiseOrAssignment,
			BitwiseXorAssignment,
			BitshiftLeftAssignment,
			BitshiftRightAssignment,
			LogicalAnd,
			LogicalOr,
			LessThan,
			LessThanOrEqual,
			GreaterThan,
			GreaterThanOrEqual,
			Equal,
			NotEqual
		};
		
		enum class ParsedLoopControlStatement : UnderlyingTokenType
		{
			Invalid = -1,
			Break,
			Continue
		};
		
		enum class ValueCategory : UnderlyingTokenType
		{
			Invalid = -1,
			LValue,
			RValue,
			Any
		};
		
		
		
		//--------------------------------------------------------------------------------------------------
		
		
		
		const std::string										getStringVerbose(ParsedVariableType pvType);
		const std::string										getStringVerbose(ParsedUnaryOperation puOperation);
		const std::string										getStringVerbose(ParsedBinaryOperation pbOperation);
		const std::string										getStringVerbose(ParsedLoopControlStatement plcStatement);
		const std::string										getStringVerbose(ValueCategory valueCategory);
		const std::string										getString(ParsedVariableType pvType);
		const std::string										getString(ParsedUnaryOperation puOperation);
		const std::string										getString(ParsedBinaryOperation pbOperation);
		const std::string										getString(ParsedLoopControlStatement plcStatement);
		const std::string										getString(ValueCategory valueCategory);
		
		bool													isTypeAllowed(ParsedUnaryOperation puOperation, ParsedVariableType pvType);
		bool													isTypeAllowed(ParsedBinaryOperation pbOperation, ParsedVariableType pvType);
		ParsedVariableType										getResultingType(ParsedUnaryOperation puOperation, ParsedVariableType inputPvType);
		ParsedVariableType										getResultingType(ParsedBinaryOperation pbOperation, ParsedVariableType inputPvType);
		
		ValueCategory											getRequiredValueCategory(ParsedUnaryOperation puOperation);
		ValueCategory											getResultingValueCategory(ParsedUnaryOperation puOperation);
		ValueCategory											getRequiredLhsValueCategory(ParsedBinaryOperation pbOperation);
		ValueCategory											getRequiredRhsValueCategory(ParsedBinaryOperation pbOperation);
		ValueCategory											getResultingValueCategory(ParsedBinaryOperation pbOperation);
	}
}

