#include "LexerTokenDefinitions.hpp"



namespace ast
{
	namespace Lexer
	{
		const std::string getStringVerbose(ParsedVariableType pvType)
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
		
		const std::string getStringVerbose(ParsedUnaryOperation puOperation)
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
				case ParsedUnaryOperation::TypecastBool					: return "TypecastBool";
				case ParsedUnaryOperation::TypecastInt					: return "TypecastInt";
				case ParsedUnaryOperation::TypecastReal					: return "TypecastReal";
				case ParsedUnaryOperation::TypecastString				: return "TypecastString";
				default													: return "Unknown";
			}
		}
		
		const std::string getStringVerbose(ParsedBinaryOperation pbOperation)
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
		
		const std::string getStringVerbose(ParsedLoopControlStatement plcStatement)
		{
			switch(plcStatement)
			{
				case ParsedLoopControlStatement::Invalid				: return "Invalid";
				case ParsedLoopControlStatement::Break					: return "Break";
				case ParsedLoopControlStatement::Continue				: return "Continue";
				default													: return "Unknown";
			}
		}
		
		const std::string getStringVerbose(ValueCategory valueCategory)
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
		
		const std::string getString(ParsedVariableType pvType)
		{
			switch(pvType)
			{
				case ParsedVariableType::Invalid						: return "invalid";
				case ParsedVariableType::Void							: return "void";
				case ParsedVariableType::Bool							: return "bool";
				case ParsedVariableType::Int							: return "int";
				case ParsedVariableType::Real							: return "real";
				case ParsedVariableType::String							: return "string";
				default													: return "unknown";
			}
		}
		
		const std::string getString(ParsedUnaryOperation puOperation)
		{
			switch(puOperation)
			{
				case ParsedUnaryOperation::Invalid						: return "invalid";
				case ParsedUnaryOperation::LogicalNot					: return "!";
				case ParsedUnaryOperation::BitwiseNot					: return "~";
				case ParsedUnaryOperation::PrefixIncrement				: return "prefix ++";
				case ParsedUnaryOperation::PrefixDecrement				: return "prefix --";
				case ParsedUnaryOperation::PostfixIncrement				: return "postfix ++";
				case ParsedUnaryOperation::PostfixDecrement				: return "postfix --";
				case ParsedUnaryOperation::UnaryPlus					: return "unary +";
				case ParsedUnaryOperation::UnaryMinus					: return "unary -";
				case ParsedUnaryOperation::TypecastBool					: return "(bool)";
				case ParsedUnaryOperation::TypecastInt					: return "(int)";
				case ParsedUnaryOperation::TypecastReal					: return "(real)";
				case ParsedUnaryOperation::TypecastString				: return "(string)";
				default													: return "unknown";
			}
		}
		
		const std::string getString(ParsedBinaryOperation pbOperation)
		{
			switch(pbOperation)
			{
				case ParsedBinaryOperation::Invalid						: return "invalid";
				case ParsedBinaryOperation::Add							: return "+";
				case ParsedBinaryOperation::Subtract					: return "-";
				case ParsedBinaryOperation::Multiply					: return "*";
				case ParsedBinaryOperation::Divide						: return "/";
				case ParsedBinaryOperation::Modulo						: return "%";
				case ParsedBinaryOperation::BitwiseAnd					: return "&";
				case ParsedBinaryOperation::BitwiseOr					: return "|";
				case ParsedBinaryOperation::BitwiseXor					: return "^";
				case ParsedBinaryOperation::BitshiftLeft				: return "<<";
				case ParsedBinaryOperation::BitshiftRight				: return ">>";
				case ParsedBinaryOperation::Assignment					: return "=";
				case ParsedBinaryOperation::AddAssignment				: return "+=";
				case ParsedBinaryOperation::SubtractAssignment			: return "-=";
				case ParsedBinaryOperation::MultiplyAssignment			: return "*=";
				case ParsedBinaryOperation::DivideAssignment			: return "/=";
				case ParsedBinaryOperation::ModuloAssignment			: return "%=";
				case ParsedBinaryOperation::BitwiseAndAssignment		: return "&=";
				case ParsedBinaryOperation::BitwiseOrAssignment			: return "|=";
				case ParsedBinaryOperation::BitwiseXorAssignment		: return "^=";
				case ParsedBinaryOperation::BitshiftLeftAssignment		: return "<<=";
				case ParsedBinaryOperation::BitshiftRightAssignment		: return ">>=";
				case ParsedBinaryOperation::LogicalAnd					: return "&&";
				case ParsedBinaryOperation::LogicalOr					: return "||";
				case ParsedBinaryOperation::LessThan					: return "<";
				case ParsedBinaryOperation::LessThanOrEqual				: return "<=";
				case ParsedBinaryOperation::GreaterThan					: return ">";
				case ParsedBinaryOperation::GreaterThanOrEqual			: return ">=";
				case ParsedBinaryOperation::Equal						: return "==";
				case ParsedBinaryOperation::NotEqual					: return "!=";
				default													: return "unknown";
			}
		}
		
		const std::string getString(ParsedLoopControlStatement plcStatement)
		{
			switch(plcStatement)
			{
				case ParsedLoopControlStatement::Invalid				: return "invalid";
				case ParsedLoopControlStatement::Break					: return "break";
				case ParsedLoopControlStatement::Continue				: return "continue";
				default													: return "unknown";
			}
		}
		
		const std::string getString(ValueCategory valueCategory)
		{
			switch(valueCategory)
			{
				case ValueCategory::Invalid								: return "invalid";
				case ValueCategory::LValue								: return "lvalue";
				case ValueCategory::RValue								: return "rvalue";
				case ValueCategory::Any									: return "any";
				default													: return "unknown";
			}
		}
		
		bool isTypeAllowed(ParsedUnaryOperation puOperation, ParsedVariableType pvType)
		{
			switch(puOperation)
			{
				case ParsedUnaryOperation::TypecastBool:															//typecast to bool: for int: true when var!=0, for real: true when var!=0.0, for string: true for "true" or "1", false otherwise
				case ParsedUnaryOperation::TypecastInt:																//typecast to int: for bool: 1 when true, 0 otherwise, for real: floor(var), for string: try to parse as int, 0 on failure
				case ParsedUnaryOperation::TypecastReal:															//typecast to real: for bool: 1.0 when true, 0.0 otherwise, for int: var is kept, for string: try to parse as real, 0.0 on failure
				case ParsedUnaryOperation::TypecastString:															//typecast to string: for bool: "true" or "false", for int and real: stringified value
					return true;
				
				case ParsedUnaryOperation::LogicalNot:																//logical not makes sense for all types except string
					return (pvType != ParsedVariableType::String);
				
				case ParsedUnaryOperation::PrefixIncrement:															//increment, decrement, unary plus and minus only make sense for numeric types
				case ParsedUnaryOperation::PrefixDecrement:
				case ParsedUnaryOperation::PostfixIncrement:
				case ParsedUnaryOperation::PostfixDecrement:
				case ParsedUnaryOperation::UnaryPlus:
				case ParsedUnaryOperation::UnaryMinus:
					return (pvType == ParsedVariableType::Int  ||  pvType == ParsedVariableType::Real);
				
				case ParsedUnaryOperation::BitwiseNot:																//bitwise not cannot be applied to real or string
					return (pvType == ParsedVariableType::Bool  ||  pvType == ParsedVariableType::Int);
				
				default:
					return false;
			}
		}
		
		bool isTypeAllowed(ParsedBinaryOperation pbOperation, ParsedVariableType pvType)
		{
			switch(pbOperation)
			{
				case ParsedBinaryOperation::Add:																		//add is normal addition for int and real, string concatenation for string
				case ParsedBinaryOperation::AddAssignment:
					return (pvType != ParsedVariableType::Bool);
				
				case ParsedBinaryOperation::Subtract:																	//normal mathematical operators only for int and real
				case ParsedBinaryOperation::Multiply:
				case ParsedBinaryOperation::Divide:
				case ParsedBinaryOperation::Modulo:
				case ParsedBinaryOperation::SubtractAssignment:
				case ParsedBinaryOperation::MultiplyAssignment:
				case ParsedBinaryOperation::DivideAssignment:
				case ParsedBinaryOperation::ModuloAssignment:
					return (pvType == ParsedVariableType::Int  ||  pvType == ParsedVariableType::Real);
				
				case ParsedBinaryOperation::BitwiseAnd:																	//bitwise operators, as above, only for bool and int
				case ParsedBinaryOperation::BitwiseOr:
				case ParsedBinaryOperation::BitwiseXor:
				case ParsedBinaryOperation::BitwiseAndAssignment:
				case ParsedBinaryOperation::BitwiseOrAssignment:
				case ParsedBinaryOperation::BitwiseXorAssignment:
					return (pvType == ParsedVariableType::Bool  ||  pvType == ParsedVariableType::Int);
				
				case ParsedBinaryOperation::BitshiftLeft:																//bitshifts are only for ints
				case ParsedBinaryOperation::BitshiftRight:
				case ParsedBinaryOperation::BitshiftLeftAssignment:
				case ParsedBinaryOperation::BitshiftRightAssignment:
					return (pvType == ParsedVariableType::Int);
				
				case ParsedBinaryOperation::LogicalAnd:																	//logical and and or are evaluated by implicitly casting the values to "bool" beforehand (see there for details)
				case ParsedBinaryOperation::LogicalOr:
				case ParsedBinaryOperation::LessThan:																	//comparison operators are evaluated by implicitly casting the values to "int" beforehand, except that "real" is kept as it is
				case ParsedBinaryOperation::LessThanOrEqual:
				case ParsedBinaryOperation::GreaterThan:
				case ParsedBinaryOperation::GreaterThanOrEqual:
				case ParsedBinaryOperation::Equal:																		//equality, inequality and assignment are applicable for all types
				case ParsedBinaryOperation::NotEqual:
				case ParsedBinaryOperation::Assignment:
					return true;

				default:
					return false;
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
				case ParsedUnaryOperation::TypecastBool:
				case ParsedUnaryOperation::TypecastInt:
				case ParsedUnaryOperation::TypecastReal:
				case ParsedUnaryOperation::TypecastString:
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
				case ParsedUnaryOperation::TypecastBool:
				case ParsedUnaryOperation::TypecastInt:
				case ParsedUnaryOperation::TypecastReal:
				case ParsedUnaryOperation::TypecastString:
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
