#pragma once



#include <type_traits>
#include <string>


namespace ast
{
	namespace Lexer
	{
		/*
		* PRECEDENCE (extracted from http://en.cppreference.com/w/c/language/operator_precedence):
		*  1. ++ --				PostfixIncrement/PostfixDecrement		left-to-right			rvalue
		*  2. ++ --				PrefixIncrement/PrefixDecrement			right-to-left			lvalue
		*     + -				UnaryPlus/UnaryMinus											all following rvalue
		*     ! ~				LogicalNot/BitwiseNot
		*     (type)			Typecast
		*     sizeof			Sizeof
		*  3. * / %				Multiply/Divide/Modulo					left-to-right
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
	
		enum class TokenType : int
		{
			Invalid = -1,
			Identifier,
			ParsedVariableType,
			ParsedUnaryOperation,
			ParsedPositionDependentUnaryOperation,
			ParsedUnaryOrBinaryOperation,
			ParsedBinaryOperation,
			ParsedRValueValueType,
			ParsedLoopControlStatement,
			If,
			Else,
			While,
			For,
			Return,
			RoundBracketOpen,
			RoundBracketClosed,
			SquareBracketOpen,
			SquareBracketClosed,
			CurlyBracketOpen,
			CurlyBracketClosed,
			Comma,
			Semicolon
		};
		
		using UnderlyingTokenType = std::underlying_type<TokenType>::type;
		
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
			Typecast,
			Sizeof
		};
		
		enum class ParsedPositionDependentUnaryOperation : UnderlyingTokenType
		{
			Invalid = -1,
			Increment,
			Decrement
		};
		
		enum class ParsedUnaryOrBinaryOperation : UnderlyingTokenType
		{
			Invalid = -1,
			Plus,
			Minus
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
		
		
		
		//--------------------------------------------------------------------------------------------------
		
		
		
		const std::string										getTokenTypeString(TokenType tType);
		const std::string										getParsedVariableTypeString(ParsedVariableType pvType);
		const std::string										getParsedUnaryOperationString(ParsedUnaryOperation puOperation);
		const std::string										getParsedPositionDependentUnaryOperationString(ParsedPositionDependentUnaryOperation ppduOperation);
		const std::string										getParsedUnaryOrBinaryOperationString(ParsedUnaryOrBinaryOperation puobOperation);
		const std::string										getParsedBinaryOperationString(ParsedBinaryOperation pbOperation);
		const std::string										getParsedLoopControlStatementString(ParsedLoopControlStatement plcStatement);
	}
}

