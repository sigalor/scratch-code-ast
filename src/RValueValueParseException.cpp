#include "RValueValueParseException.hpp"



namespace ast
{
	RValueValueParseException::RValueValueParseException(std::string newMsg) : msg(newMsg) { }
			
	const char* RValueValueParseException::what() const throw()
	{
		return msg.c_str();
	}
	
	const std::string& RValueValueParseException::getMsg()
	{
		return msg;
	}
}
