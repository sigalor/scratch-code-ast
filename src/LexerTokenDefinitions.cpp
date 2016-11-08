#include "LexerTokenDefinitions.hpp"



namespace ast
{
	namespace Lexer
	{
		const std::string getTokenTypeString(TokenType tType)
		{
			switch(tType)
			{
				case TokenType::Invalid									: return "Invalid";
				case TokenType::Identifier								: return "Identifier";
				case TokenType::ParsedVariableType						: return "ParsedVariableType";
				case TokenType::ParsedUnaryOperation					: return "ParsedUnaryOperation";
				case TokenType::ParsedPositionDependentUnaryOperation	: return "ParsedPositionDependentUnaryOperation";
				case TokenType::ParsedUnaryOrBinaryOperation			: return "ParsedUnaryOrBinaryOperation";
				case TokenType::ParsedBinaryOperation					: return "ParsedBinaryOperation";
				case TokenType::ParsedRValueValueType					: return "ParsedRValueValueType";
				case TokenType::ParsedLoopControlStatement				: return "ParsedLoopControlStatement";
				case TokenType::If										: return "If";
				case TokenType::Else									: return "Else";
				case TokenType::While									: return "While";
				case TokenType::For										: return "For";
				case TokenType::Return									: return "Return";
				case TokenType::RoundBracketOpen						: return "RoundBracketOpen";
				case TokenType::RoundBracketClosed						: return "RoundBracketClosed";
				case TokenType::SquareBracketOpen						: return "SquareBracketOpen";
				case TokenType::SquareBracketClosed						: return "SquareBracketClosed";
				case TokenType::CurlyBracketOpen						: return "CurlyBracketOpen";
				case TokenType::CurlyBracketClosed						: return "CurlyBracketClosed";
				case TokenType::Comma									: return "Comma";
				case TokenType::Semicolon								: return "Semicolon";
				case TokenType::ParserLexerTokenDummy					: return "ParserLexerTokenDummy";
				//case TokenType::ParserValueDummy						: return "ParserValueDummy";
				default													: return "Unknown";
			}
		}
		
		const std::string getParsedVariableTypeString(ParsedVariableType pvType)
		{
			switch(pvType)
			{
				case ParsedVariableType::Invalid						: return "Invalid";
				case ParsedVariableType::Void							: return "Void";
				case ParsedVariableType::Bool							: return "Bool";
				case ParsedVariableType::Int							: return "Int";
				case ParsedVariableType::Real							: return "Real";
				case ParsedVariableType::String							: return "String";
				default													: return "Unknown";
			}
		}
		
		const std::string getParsedUnaryOperationString(ParsedUnaryOperation puOperation)
		{
			switch(puOperation)
			{
				case ParsedUnaryOperation::Invalid						: return "Invalid";
				case ParsedUnaryOperation::LogicalNot					: return "LogicalNot";
				case ParsedUnaryOperation::BitwiseNot					: return "BitwiseNot";
				case ParsedUnaryOperation::PrefixIncrement				: return "PrefixIncrement";
				case ParsedUnaryOperation::PrefixDecrement				: return "PrefixDecrement";
				case ParsedUnaryOperation::PostfixIncrement				: return "PostfixIncrement";
				case ParsedUnaryOperation::PostfixDecrement				: return "PostfixDecrement";
				case ParsedUnaryOperation::UnaryPlus					: return "UnaryPlus";
				case ParsedUnaryOperation::UnaryMinus					: return "UnaryMinus";
				case ParsedUnaryOperation::Typecast						: return "Typecast";
				case ParsedUnaryOperation::Sizeof						: return "Sizeof";
				default													: return "Unknown";
			}
		}
		
		const std::string getParsedPositionDependentUnaryOperationString(ParsedPositionDependentUnaryOperation ppduOperation)
		{
			switch(ppduOperation)
			{
				case ParsedPositionDependentUnaryOperation::Invalid		: return "Invalid";
				case ParsedPositionDependentUnaryOperation::Increment	: return "Increment";
				case ParsedPositionDependentUnaryOperation::Decrement	: return "Decrement";
				default													: return "Unknown";
			}
		}
		
		const std::string getParsedUnaryOrBinaryOperationString(ParsedUnaryOrBinaryOperation puobOperation)
		{
			switch(puobOperation)
			{
				case ParsedUnaryOrBinaryOperation::Invalid				: return "Invalid";
				case ParsedUnaryOrBinaryOperation::Plus					: return "Plus";
				case ParsedUnaryOrBinaryOperation::Minus				: return "Minus";
				default													: return "Unknown";
			}
		}
		
		const std::string getParsedBinaryOperationString(ParsedBinaryOperation pbOperation)
		{
			switch(pbOperation)
			{
				case ParsedBinaryOperation::Invalid						: return "Invalid";
				case ParsedBinaryOperation::Add							: return "Add";
				case ParsedBinaryOperation::Subtract					: return "Subtract";
				case ParsedBinaryOperation::Multiply					: return "Multiply";
				case ParsedBinaryOperation::Divide						: return "Divide";
				case ParsedBinaryOperation::Modulo						: return "Modulo";
				case ParsedBinaryOperation::BitwiseAnd					: return "BitwiseAnd";
				case ParsedBinaryOperation::BitwiseOr					: return "BitwiseOr";
				case ParsedBinaryOperation::BitwiseXor					: return "BitwiseXor";
				case ParsedBinaryOperation::BitshiftLeft				: return "BitshiftLeft";
				case ParsedBinaryOperation::BitshiftRight				: return "BitshiftRight";
				case ParsedBinaryOperation::Assignment					: return "Assignment";
				case ParsedBinaryOperation::AddAssignment				: return "AddAssignment";
				case ParsedBinaryOperation::SubtractAssignment			: return "SubtractAssignment";
				case ParsedBinaryOperation::MultiplyAssignment			: return "MultiplyAssignment";
				case ParsedBinaryOperation::DivideAssignment			: return "DivideAssignment";
				case ParsedBinaryOperation::ModuloAssignment			: return "ModuloAssignment";
				case ParsedBinaryOperation::BitwiseAndAssignment		: return "BitwiseAndAssignment";
				case ParsedBinaryOperation::BitwiseOrAssignment			: return "BitwiseOrAssignment";
				case ParsedBinaryOperation::BitwiseXorAssignment		: return "BitwiseXorAssignment";
				case ParsedBinaryOperation::BitshiftLeftAssignment		: return "BitshiftLeftAssignment";
				case ParsedBinaryOperation::BitshiftRightAssignment		: return "BitshiftRightAssignment";
				case ParsedBinaryOperation::LogicalAnd					: return "LogicalAnd";
				case ParsedBinaryOperation::LogicalOr					: return "LogicalOr";
				case ParsedBinaryOperation::LessThan					: return "LessThan";
				case ParsedBinaryOperation::LessThanOrEqual				: return "LessThanOrEqual";
				case ParsedBinaryOperation::GreaterThan					: return "GreaterThan";
				case ParsedBinaryOperation::GreaterThanOrEqual			: return "GreaterThanOrEqual";
				case ParsedBinaryOperation::Equal						: return "Equal";
				case ParsedBinaryOperation::NotEqual					: return "NotEqual";
				default													: return "Unknown";
			}
		}
		
		const std::string getParsedRValueValueTypeString(ParsedRValueValueType prvvType)
		{
			switch(prvvType)
			{
				case ParsedRValueValueType::Invalid						: return "Invalid";
				case ParsedRValueValueType::Bool						: return "Bool";
				case ParsedRValueValueType::Char						: return "Char";
				case ParsedRValueValueType::EscapeSequence				: return "EscapeSequence";
				case ParsedRValueValueType::OctalEscapeSequence			: return "OctalEscapeSequence";
				case ParsedRValueValueType::HexadecimalEscapeSequence	: return "HexadecimalEscapeSequence"; 
				case ParsedRValueValueType::ShortBinary					: return "ShortBinary";
				case ParsedRValueValueType::ShortOctal					: return "ShortOctal";
				case ParsedRValueValueType::ShortDecimal				: return "ShortDecimal";
				case ParsedRValueValueType::ShortHexadecimal			: return "ShortHexadecimal";
				case ParsedRValueValueType::IntBinary					: return "IntBinary";
				case ParsedRValueValueType::IntOctal					: return "IntOctal";
				case ParsedRValueValueType::IntDecimal					: return "IntDecimal";
				case ParsedRValueValueType::IntHexadecimal				: return "IntHexadecimal";
				case ParsedRValueValueType::LongBinary					: return "LongBinary";
				case ParsedRValueValueType::LongOctal					: return "LongOctal";
				case ParsedRValueValueType::LongDecimal					: return "LongDecimal";
				case ParsedRValueValueType::LongHexadecimal				: return "LongHexadecimal";
				case ParsedRValueValueType::Float						: return "Float";
				case ParsedRValueValueType::Double						: return "Double";
				default													: return "Unknown";
			}
		}
		
		const std::string getParsedLoopControlStatementString(ParsedLoopControlStatement plcStatement)
		{
			switch(plcStatement)
			{
				case ParsedLoopControlStatement::Break					: return "Break";
				case ParsedLoopControlStatement::Continue				: return "Continue";
				default													: return "Unknown";
			}
		}
	}
}
