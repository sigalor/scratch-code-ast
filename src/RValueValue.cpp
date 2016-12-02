/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code-ast/src/RValueValue.cpp
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



#include "RValueValue.hpp"



namespace ast
{
	const int RValueValue::uniqueId = 0x00012311;

	RValueValue::RValueValue(int newId) : RValue(newId) { }
	RValueValue::RValueValue(int newId, std::shared_ptr<Node> newParent) : RValue(newId, newParent) { }
	RValueValue::RValueValue(int newId, std::shared_ptr<Node> newParent, bool newValue) : RValue(newId, newParent), value(newValue) { }

	RValueValue::RValueValue() : RValue(uniqueId), type(Lexer::ParsedVariableType::Invalid) { }
	RValueValue::RValueValue(std::shared_ptr<Node> newParent) : RValue(uniqueId, newParent), type(Lexer::ParsedVariableType::Invalid) { }
	RValueValue::RValueValue(std::shared_ptr<Node> newParent, bool newValue) : RValue(uniqueId, newParent), type(Lexer::ParsedVariableType::Bool), value(newValue) { }
	RValueValue::RValueValue(std::shared_ptr<Node> newParent, uint64_t newValue) : RValue(uniqueId, newParent), type(Lexer::ParsedVariableType::Int), value(newValue) { }
	RValueValue::RValueValue(std::shared_ptr<Node> newParent, double newValue) : RValue(uniqueId, newParent), type(Lexer::ParsedVariableType::Real), value(newValue) { }
	RValueValue::RValueValue(std::shared_ptr<Node> newParent, const std::string& newValue) : RValue(uniqueId, newParent), type(Lexer::ParsedVariableType::String), value(newValue) { }
	
	Lexer::ParsedVariableType RValueValue::getType()
	{
		return type;
	}
	
	RValueValue::ValueVariantType& RValueValue::getValue()
	{
		return value;
	}
	
	const std::string RValueValue::getValueString() const
	{
		return toString(value);
	}
	
	void RValueValue::setValue(bool newValue)
	{
		type = Lexer::ParsedVariableType::Bool;
		value = newValue;
	}
	
	void RValueValue::setValue(uint64_t newValue)
	{
		type = Lexer::ParsedVariableType::Int;
		value = newValue;
	}
	
	void RValueValue::setValue(double newValue)
	{
		type = Lexer::ParsedVariableType::Real;
		value = newValue;
	}
	
	void RValueValue::setValue(const std::string& newValue)
	{
		type = Lexer::ParsedVariableType::String;
		value = newValue;
	}
	
	/*void RValueValue::setValue(std::string newValue)
	{
		if(inputType == Lexer::ParsedRValueValueType::Invalid)
			return;
		
		throw RValueValueParseException("RValueValue parsing is not implemented yet");
		
		using rvt = Lexer::ParsedRValueValueType;
		using pvt = Lexer::ParsedVariableType;
		if(inputType == rvt::Bool)
		{
			type = pvt::Bool;
			bool val = (newValue == "true");
			setValueRaw(&val);
		}
		else if(inputType == rvt::Char  ||  inputType == rvt::EscapeSequence  ||  inputType == rvt::OctalEscapeSequence  ||  inputType == rvt::HexadecimalEscapeSequence)
		{
			type = pvt::Char;
			if(inputType == rvt::Char)
			{
				char val = newValue[1];
				setValueRaw(&val);
			}
			else if(inputType == rvt::EscapeSequence)
			{
				char val = 0;
				switch(newValue[2])																			//reference: https://en.wikipedia.org/wiki/Escape_sequences_in_C#Table_of_escape_sequences
				{
					case 'a'  : val = 0x07; break;
					case 'b'  : val = 0x08; break;
					case 'f'  : val = 0x0C; break;
					case 'n'  : val = 0x0A; break;
					case 'r'  : val = 0x0D; break;
					case 't'  : val = 0x09; break;
					case 'v'  : val = 0x0B; break;
					case '\\' : val = 0x5C; break;
					case '\'' : val = 0x27; break;
					case '"'  : val = 0x22; break;
					case '?'  : val = 0x3F; break;
				}
				setValueRaw(&val);
			}
			else if(inputType == rvt::OctalEscapeSequence)
			{
				std::string oct = newValue.substr(2, 3);
				long octLong = strtol(oct.c_str(), nullptr, 8);
				if(octLong > 255)
					throw RValueValueParseException("octal escape sequence too large");
				uint8_t octChar = (uint8_t)octLong;
				setValueRaw(&octChar);
			}
			else if(inputType == rvt::HexadecimalEscapeSequence)
			{
				std::string hex = newValue.substr(3, 2);
				uint8_t hexChar = static_cast<uint8_t>(strtol(hex.c_str(), nullptr, 16));
				setValueRaw(&hexChar);
			}
		}
		else if(inputType == rvt::ShortBinary  ||  inputType == rvt::ShortOctal  ||  inputType == rvt::ShortDecimal  ||  inputType == rvt::ShortHexadecimal  ||
				inputType == rvt::IntBinary  ||  inputType == rvt::IntOctal  ||  inputType == rvt::IntDecimal  ||  inputType == rvt::IntHexadecimal  ||
				inputType == rvt::LongBinary  ||  inputType == rvt::LongOctal  ||  inputType == rvt::LongDecimal  ||  inputType == rvt::LongHexadecimal)
		{
			int base = 0;
			
			if(inputType == rvt::ShortBinary  ||  inputType == rvt::ShortOctal  ||  inputType == rvt::ShortDecimal  ||  inputType == rvt::ShortHexadecimal)
				type = pvt::Short;
			else if(inputType == rvt::IntBinary  ||  inputType == rvt::IntOctal  ||  inputType == rvt::IntDecimal  ||  inputType == rvt::IntHexadecimal)
				type = pvt::Int;
			else if(inputType == rvt::LongBinary  ||  inputType == rvt::LongOctal  ||  inputType == rvt::LongDecimal  ||  inputType == rvt::LongHexadecimal)
				type = pvt::Long;
			
			if(inputType == rvt::ShortBinary  ||  inputType == rvt::IntBinary  ||  inputType == rvt::LongBinary)
				base = 2;
			else if(inputType == rvt::ShortOctal  ||  inputType == rvt::IntOctal  ||  inputType == rvt::LongOctal)
				base = 8;
			else if(inputType == rvt::ShortDecimal  ||  inputType == rvt::IntDecimal  ||  inputType == rvt::LongDecimal)
				base = 10;
			else if(inputType == rvt::ShortHexadecimal  ||  inputType == rvt::IntHexadecimal  ||  inputType == rvt::LongHexadecimal)
				base = 16;
			
			uint64_t converted = static_cast<uint64_t>(strtoll(newValue.substr(0, newValue.size()-(type==pvt::Int ? 0 : 1)).c_str(), nullptr, base));
			if(errno == ERANGE)
				throw RValueValueParseException("value not internally representable");
			
			if(type == pvt::Short  &&  converted > (static_cast<uint64_t>(1)<<15))							//short values must be less than or equal 32768. a minus before any number is an unary operator and saved in another LexerToken. because this AST implementation currently supports signed values only, the absolute of no short value may be larger than 32768 == 2^15 == 1<<15. all values in *this* class are saved *unsigned*!
				throw RValueValueParseException("'short' value too large");
			else if(type == pvt::Int  &&  converted > (static_cast<uint64_t>(1)<<31))
				throw RValueValueParseException("'int' value too large");
			else if(type == pvt::Long  &&  converted > (static_cast<uint64_t>(1)<<63))
				throw RValueValueParseException("'long' value too large");
			
			
			if(type == pvt::Short) { setValueRaw(static_cast<uint16_t>(converted)); }						//it is not possible to pass the address of a rvalue, so use the call-by-value version of 'setValueRaw' here
			if(type == pvt::Int)   { setValueRaw(static_cast<uint32_t>(converted)); }
			if(type == pvt::Long)  { setValueRaw(&converted); }
		}
		else if(inputType == rvt::Float)
		{
			float val = strtof(newValue.substr(0, newValue.size()-1).c_str(), nullptr);
			setValueRaw(&val);
		}
		else if(inputType == rvt::Double)
		{
			double val = strtod(newValue.c_str(), nullptr);
			setValueRaw(&val);
		}
	}*/
}
