#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <iostream>
#include <vector>
#include <string>

class Message 
{
	public:
		Message() : header_names({"Default Header Name 1"}),fields({"Default field1"}) {}
		Message(std::string header) : header_names({header}),
					      fields ({"Default field1"}) {} 

		std::string getHeaderUsingField (const std::string&) const;
		std::string getFieldUsingHeader (const std::string&) const;
		void addToMessage (const std::string& ) const;
		void addToMessage (const std::string&,const std::string&) const;
		

	private:
		std::vector <std::string> header_names;
		std::vector <std::string> fields;
};

#endif


