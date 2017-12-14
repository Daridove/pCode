#include <iostream>
#include <fstream>

int main()
{
  int lineCount = 0;
  
  std::string line;
  std::ofstream outFile("blockMeshFile");
  std::ifstream fileFOAM("/home/debal/OpenFOAM/debal-4.1/run/cavity/system/blockMeshDict");

  if (!fileFOAM)
  {
    std::cout << std::endl << "Could not Open the File!" << std::endl;
  }
  else
  {
    std::cout <<  std::endl << "Successfully opened File!  \n";

    while((std::getline(fileFOAM,line)))
    {
      outFile << line ;
      outFile << "\n";
      if (line == "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //") break;
    }
  }

  return 0;

}
