#include <string>
#include <vector>
#include <iostream>

class VecMsg {

	public:
		VecMsg() : msgs({"msg1"}), flds({"fld1"}) {}
		
		const *std::string getDataUsePos(int);

		const std::string getMsgUseFld(const std::string&);
		const std::string getFldUseMsg(const std::string&); 
	private:
		std::vector<std::string> msgs;
 		std::vector<std::string> flds;
};

const *std::string VecMsg::getDataUsePos(int pos)
{
		

const std::string VecMsg::getMsgUseFld(const std::string& gFld)
{
	int pos_msg = 0;

	const std::string returnMsg = "ERROR: NO FIELD FOUND WITH GIVEN HEADER!";


	std::vector<std::string>::const_iterator itr;
	
	for (itr=msgs.begin(); itr!=msgs.end(); ++itr)
	{
		if(*itr==gFld)
			pos_msg = itr - msgs.begin();
	}

	if (pos_msg == 0) 
		return returnMsg; 
	else
		return msgs[pos_msg];

}
 

const std::string VecMsg::getFldUseMsg(const std::string& gMsg)
{
	int pos_fld = 0;
	const std::string returnFld = "ERROR: NO HEADER FOUND WITH GIVEN FIELD!";

	std::vector<std::string>::const_iterator itr;
	
	for (itr=flds.begin(); itr!=flds.end(); ++itr)
	{
		if(*itr==gMsg)
			pos_fld = itr - flds.begin();
	}

	if (pos_fld == 0) 
		return returnFld;
 	else
		return msgs[pos_fld];

	// delete itr;

}


int main (int argc, char** argv)
{
	const std::string arr[] = {"header1","header2"};
	std::vector<std::string> headers (arr, arr + sizeof(arr)/sizeof(arr[0]));
	
	headers.push_back("Hello1");
	headers.push_back("Hello2");

	VecMsg V1;

	std::cout << std::endl << headers[0] << std::endl << headers[1] << std::endl << "\n"; 
	std::cout << headers.size() << std::endl
	
	std::string strReply =  V1.getMsgUseFld("") << "\n";
	
//	std::cout << static_cast<int> (headers.end()) << std::endl;	
	std::cout << headers.begin() << std::endl;	
	return 0;
}
