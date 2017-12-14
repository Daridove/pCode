#include "Message.h"

std::string Message::getHeaderUsingField (const std::string given_field) const
{
	int pos_field = 0;
	vector<string>::const_iterator itrF; 

	for (itrF=fields.begin(); itrF!=fields.end(); ++itrF)
	{
		if(given_field==*itrF)
			pos_field = itrF - fields.begin();
	}
	
	return header_names(pos_field);	
	
}

std::string Message::getFieldUsingHeader (const std::string given_header) const
{
	int pos_header = 0;
	vector<string>::const_iterator itrH; 
	for (itrH=header_names.begin(); itrH!=header_names.end(); ++itrH)
	{
		if(given_header==*itrH)
			pos_header = itrH - header_names.begin();
	}
	
	return fields(pos_header);
}	

void Message::addToMessage (const std::string& addedHeader) const 
{
	header_names.push_back(addedHeader);
	std::string defaultField = "filed";
	int posFieldEnd = fields.end();
	fields.push_back(defaultField + std::to_string(posFieldEnd));
}

void Message::addMessage (const std::string& addedHeader, const std::string& addedField) const
{
	header_names.push_back(AddedHeader);
	fields.push_back(addedField);
}
