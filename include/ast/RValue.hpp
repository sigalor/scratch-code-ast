/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/include/ast/RValue.hpp
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



#include <memory>

#include "Node.hpp"
#include "Value.hpp"



namespace ast
{
	class RValue : public Value
	{
		public:
			static const int									uniqueId;
	
		private:
		
		protected:
			RValue(int newId);
			RValue(int newId, std::shared_ptr<Node> newParent);
		
		public:
			RValue();
			RValue(std::shared_ptr<Node> newParent);
			virtual Lexer::ValueCategory						getValueCategory() { return Lexer::ValueCategory::RValue; }
	};
}