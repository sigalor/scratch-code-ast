/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/include/ast/RValueValue.hpp
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



#include <cstdlib>
#include <vector>
#include <memory>
#include <boost/variant.hpp>																						//TODO: when C++17 becomes available/more widespread, use std::variant

#include "Node.hpp"
#include "RValue.hpp"
#include "LexerTokenDefinitions.hpp"
#include "Utilities.hpp"



namespace ast
{
	class RValueValue : public RValue
	{
		public:
			static const int									uniqueId;
	
		private:
			Lexer::ParsedVariableType							type;
			boost::variant<bool, uint64_t, double, std::string>	value;												//may contain values for all variable types in ast::Lexer::ParsedVariableType
		
		protected:
			RValueValue(int newId);
			RValueValue(int newId, std::shared_ptr<Node> newParent);
			RValueValue(int newId, std::shared_ptr<Node> newParent, bool newValue);
		
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
			virtual Lexer::ParsedVariableType					getEffectiveType() { return type; }
			void												setValue(bool newValue);
			void												setValue(uint64_t newValue);
			void												setValue(double newValue);
			void												setValue(const std::string& newValue);
	};
}
