#include <iostream>
#include <fstream>
#include <sstream>

int main (int argc, char** argv)
{
  std::string inFieldStr;
  char strChar = ' ';

  double inFieldVal = 0;
  int strCount = 0, charCount = 0;

  std::string line;
  std::string str_content;

  std::ifstream input("/home/debal/OpenFOAM/debal-4.1/run/cavity/0/p");
  
  if (!input) std::cerr << "Could not open the file !" <<std::endl;
  else 
  {
    /*std::cout << "File reachable !" << std::endl ;
    input >> inFieldStr;
    std::cout << std::endl << inFieldStr << "\n";
      
    input >> inFieldStr;
    std::cout << inFieldStr << "\n";*/

    while(std::getline(input,line))
    {
	str_content += line;
        charCount = 0;

        while ((line[charCount] != ' ') && (charCount < line.length()))
	{
	  inFieldStr += line[charCount];
	  ++charCount;
	  //inFieldVal = "uniform 0";
	}
	
	if (inFieldStr == "Dimension") 
	{
	 std::cout << "\n found it : " << inFieldStr << std::endl;
	}

	str_content.push_back('\n');

        ++strCount;
  
     }
  }
   
   std::cout << " \n" << inFieldStr << std::endl;
   std::cout << "\n" << str_content << "\n";
   return 0;
}
