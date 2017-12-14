#include <iostream>
#include<cmath>

#ifndef _MYFUNCTORCLASS_
#define _MYFUNCTORCLASS_

class myFucntorClass
{
	public:
		myFunctorClass (int x) : _x(x) {}
		int operator() (int y) { return _x+ y}
	private:	
		int _x;
};

class Message
{
	public:
		Message(const std::string& inputstr) : header_name(inputstr) {}
		std::string getHeader (const std::string& header_name) const;
		// other methods .. if any ..
	private:
		std::string header_name;
};

class MessageSorter
{
	public:
		// take the fields to sort by in the constructor
		MessageSorter (const std::string& field) : _field(field) {}
		bool operator()  (const Message& lhs, const Message& rhs)
		{
			// get the field to sort by and make the comparison 
			return lhs.getHeader(_field) < rhs.getHeader(_field);
		}
	private:
		std::string _field;
};	

#endif	
