#pragma once



#include <string>
#include <exception>



namespace ast
{
	class RValueValueParseException : public std::exception
	{
		protected:
			std::string											msg;
		
		public:
			explicit RValueValueParseException(std::string newMsg);
			
			virtual const char*									what() const throw();
			const std::string&									getMsg();
	};
}

