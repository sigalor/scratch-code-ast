#include "LexerTokenDefinitions.hpp"



namespace ast
{
	namespace Lexer
	{
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
		
		const std::string getParsedLoopControlStatementString(ParsedLoopControlStatement plcStatement)
		{
			switch(plcStatement)
			{
				case ParsedLoopControlStatement::Invalid				: return "Invalid";
				case ParsedLoopControlStatement::Break					: return "Break";
				case ParsedLoopControlStatement::Continue				: return "Continue";
				default													: return "Unknown";
			}
		}
		
		const std::string getValueCategoryString(ValueCategory valueCategory)
		{
			switch(valueCategory)
			{
				case ValueCategory::Invalid								: return "Invalid";
				case ValueCategory::LValue								: return "LValue";
				case ValueCategory::RValue								: return "RValue";
				case ValueCategory::Any									: return "Any";
				default													: return "Unknown";
			}
		}
		
		ValueCategory getRequiredValueCategory(ParsedUnaryOperation puOperation)
		{
			switch(puOperation)
			{
				case ParsedUnaryOperation::PrefixIncrement:
				case ParsedUnaryOperation::PrefixDecrement:
				case ParsedUnaryOperation::PostfixIncrement:
				case ParsedUnaryOperation::PostfixDecrement:
					return ValueCategory::LValue;
			
				case ParsedUnaryOperation::LogicalNot:
				case ParsedUnaryOperation::BitwiseNot:
				case ParsedUnaryOperation::UnaryPlus:
				case ParsedUnaryOperation::UnaryMinus:
				case ParsedUnaryOperation::Typecast:
				case ParsedUnaryOperation::Sizeof:
					return ValueCategory::Any;
			
				default:
					return ValueCategory::Invalid;
			}
		}
		
		ValueCategory getResultingValueCategory(ParsedUnaryOperation puOperation)
		{
			switch(puOperation)
			{
				case ParsedUnaryOperation::PrefixIncrement:
				case ParsedUnaryOperation::PrefixDecrement:
					return ValueCategory::LValue;
			
				case ParsedUnaryOperation::LogicalNot:
				case ParsedUnaryOperation::BitwiseNot:
				case ParsedUnaryOperation::PostfixIncrement:
				case ParsedUnaryOperation::PostfixDecrement:
				case ParsedUnaryOperation::UnaryPlus:
				case ParsedUnaryOperation::UnaryMinus:
				case ParsedUnaryOperation::Typecast:
				case ParsedUnaryOperation::Sizeof:
					return ValueCategory::RValue;
			
				default:
					return ValueCategory::Invalid;
			}
		}
		
		ValueCategory getRequiredLhsValueCategory(ParsedBinaryOperation pbOperation)
		{
			switch(pbOperation)
			{
				case ParsedBinaryOperation::Add:
				case ParsedBinaryOperation::Subtract:
				case ParsedBinaryOperation::Multiply:
				case ParsedBinaryOperation::Divide:
				case ParsedBinaryOperation::Modulo:
				case ParsedBinaryOperation::BitwiseAnd:
				case ParsedBinaryOperation::BitwiseOr:
				case ParsedBinaryOperation::BitwiseXor:
				case ParsedBinaryOperation::BitshiftLeft:
				case ParsedBinaryOperation::BitshiftRight:
				case ParsedBinaryOperation::LogicalAnd:
				case ParsedBinaryOperation::LogicalOr:
				case ParsedBinaryOperation::LessThan:
				case ParsedBinaryOperation::LessThanOrEqual:
				case ParsedBinaryOperation::GreaterThan:
				case ParsedBinaryOperation::GreaterThanOrEqual:
				case ParsedBinaryOperation::Equal:
				case ParsedBinaryOperation::NotEqual:
					return ValueCategory::Any;
				
				case ParsedBinaryOperation::Assignment:
				case ParsedBinaryOperation::AddAssignment:
				case ParsedBinaryOperation::SubtractAssignment:
				case ParsedBinaryOperation::MultiplyAssignment:
				case ParsedBinaryOperation::DivideAssignment:
				case ParsedBinaryOperation::ModuloAssignment:
				case ParsedBinaryOperation::BitwiseAndAssignment:
				case ParsedBinaryOperation::BitwiseOrAssignment:
				case ParsedBinaryOperation::BitwiseXorAssignment:
				case ParsedBinaryOperation::BitshiftLeftAssignment:
				case ParsedBinaryOperation::BitshiftRightAssignment:
					return ValueCategory::LValue;
				
				default:
					return ValueCategory::Invalid;
			}
		}
		
		ValueCategory getRequiredRhsValueCategory(ParsedBinaryOperation pbOperation)
		{
			switch(pbOperation)
			{
				case ParsedBinaryOperation::Add:
				case ParsedBinaryOperation::Subtract:
				case ParsedBinaryOperation::Multiply:
				case ParsedBinaryOperation::Divide:
				case ParsedBinaryOperation::Modulo:
				case ParsedBinaryOperation::BitwiseAnd:
				case ParsedBinaryOperation::BitwiseOr:
				case ParsedBinaryOperation::BitwiseXor:
				case ParsedBinaryOperation::BitshiftLeft:
				case ParsedBinaryOperation::BitshiftRight:
				case ParsedBinaryOperation::LogicalAnd:
				case ParsedBinaryOperation::LogicalOr:
				case ParsedBinaryOperation::LessThan:
				case ParsedBinaryOperation::LessThanOrEqual:
				case ParsedBinaryOperation::GreaterThan:
				case ParsedBinaryOperation::GreaterThanOrEqual:
				case ParsedBinaryOperation::Equal:
				case ParsedBinaryOperation::NotEqual:
				case ParsedBinaryOperation::Assignment:
				case ParsedBinaryOperation::AddAssignment:
				case ParsedBinaryOperation::SubtractAssignment:
				case ParsedBinaryOperation::MultiplyAssignment:
				case ParsedBinaryOperation::DivideAssignment:
				case ParsedBinaryOperation::ModuloAssignment:
				case ParsedBinaryOperation::BitwiseAndAssignment:
				case ParsedBinaryOperation::BitwiseOrAssignment:
				case ParsedBinaryOperation::BitwiseXorAssignment:
				case ParsedBinaryOperation::BitshiftLeftAssignment:
				case ParsedBinaryOperation::BitshiftRightAssignment:
					return ValueCategory::Any;
				
				default:
					return ValueCategory::Invalid;
			}
		}
		
		ValueCategory getResultingValueCategory(ParsedBinaryOperation pbOperation)
		{
			switch(pbOperation)
			{
				case ParsedBinaryOperation::Add:
				case ParsedBinaryOperation::Subtract:
				case ParsedBinaryOperation::Multiply:
				case ParsedBinaryOperation::Divide:
				case ParsedBinaryOperation::Modulo:
				case ParsedBinaryOperation::BitwiseAnd:
				case ParsedBinaryOperation::BitwiseOr:
				case ParsedBinaryOperation::BitwiseXor:
				case ParsedBinaryOperation::BitshiftLeft:
				case ParsedBinaryOperation::BitshiftRight:
				case ParsedBinaryOperation::LogicalAnd:
				case ParsedBinaryOperation::LogicalOr:
				case ParsedBinaryOperation::LessThan:
				case ParsedBinaryOperation::LessThanOrEqual:
				case ParsedBinaryOperation::GreaterThan:
				case ParsedBinaryOperation::GreaterThanOrEqual:
				case ParsedBinaryOperation::Equal:
				case ParsedBinaryOperation::NotEqual:
					return ValueCategory::RValue;
				
				case ParsedBinaryOperation::Assignment:
				case ParsedBinaryOperation::AddAssignment:
				case ParsedBinaryOperation::SubtractAssignment:
				case ParsedBinaryOperation::MultiplyAssignment:
				case ParsedBinaryOperation::DivideAssignment:
				case ParsedBinaryOperation::ModuloAssignment:
				case ParsedBinaryOperation::BitwiseAndAssignment:
				case ParsedBinaryOperation::BitwiseOrAssignment:
				case ParsedBinaryOperation::BitwiseXorAssignment:
				case ParsedBinaryOperation::BitshiftLeftAssignment:
				case ParsedBinaryOperation::BitshiftRightAssignment:
					return ValueCategory::LValue;
				
				default:
					return ValueCategory::Invalid;
			}
		}
	}
}
