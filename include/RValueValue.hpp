#pragma once



#include <cstdlib>
#include <vector>
#include <memory>
#include <boost/variant.hpp>																						//TODO: when C++17 becomes available/more widespread, use std::variant

#include "Node.hpp"
#include "RValue.hpp"
#include "LexerTokenDefinitions.hpp"
#include "RValueValueParseException.hpp"
#include "Stringifyer.hpp"



namespace ast
{
	class RValueValue : public RValue
	{
		public:
			static const int									uniqueId = 0x00012311;
	
		private:
			Lexer::ParsedVariableType							type;
			boost::variant<bool, uint64_t, double, std::string>	value;												//may contain values for all variable types in ast::Lexer::ParsedVariableType
		
		protected:
			//RValueValue(int newId);
			//RValueValue(int newId, std::shared_ptr<Node> newParent);
			//RValueValue(int newId, std::shared_ptr<Node> newParent, bool newValue);
		
		public:
			using ValueVariantType = decltype(value);
		
			RValueValue();
			RValueValue(std::shared_ptr<Node> newParent);
			RValueValue(std::shared_ptr<Node> newParent, bool newValue);
			RValueValue(std::shared_ptr<Node> newParent, uint64_t newValue);
			RValueValue(std::shared_ptr<Node> newParent, double newValue);
			RValueValue(std::shared_ptr<Node> newParent, const std::string& newValue);
			
			Lexer::ParsedVariableType							getType();
			ValueVariantType&									getValue();
			const std::string									getValueString() const;
			void												setValue(bool newValue);
			void												setValue(uint64_t newValue);
			void												setValue(double newValue);
			void												setValue(const std::string& newValue);
	};
}
