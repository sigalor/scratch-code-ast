#pragma once



#include <cstdlib>
#include <vector>
#include <memory>

#include "Node.hpp"
#include "RValue.hpp"
#include "LexerTokenDefinitions.hpp"
#include "RValueValueParseException.hpp"



namespace ast
{
	class RValueValue : public RValue
	{
		public:
			static const int									uniqueId = 0x00012311;
	
		private:
			Lexer::ParsedRValueValueType						inputType;
			Lexer::ParsedVariableType							type;
			std::vector<uint8_t>								value;
		
			template<typename T>
			void setValueRaw(T* newValue)
			{
				uint8_t* valPtr = reinterpret_cast<uint8_t*>(newValue);
				value = std::vector<uint8_t>(valPtr, valPtr+sizeof(T));
			}
			
			template<typename T>
			void setValueRaw(T newValue)
			{
				setValueRaw(&newValue);
			}
		
		protected:
			//RValueValue(int newId);
			//RValueValue(int newId, std::shared_ptr<Node> newParent);
			//RValueValue(int newId, std::shared_ptr<Node> newParent, bool newValue);
		
		public:
			RValueValue();
			RValueValue(std::shared_ptr<Node> newParent);
			//RValueValue(std::shared_ptr<Node> newParent, bool newValue);
			
			Lexer::ParsedRValueValueType						getInputType();
			Lexer::ParsedVariableType							getType();
			template<typename T> T								getValue() { return *reinterpret_cast<T*>(value.data()); }
			const std::vector<uint8_t>&							getValueRaw();
			void												setInputType(Lexer::ParsedRValueValueType newInputType);
			void												setValue(std::string newValue);
	};
}
