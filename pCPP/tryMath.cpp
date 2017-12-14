#include <iostream>
#include <vector>
#include <cmath>

template<typename StructName>
struct DefVecStruct
{
     std::vector<StructName> elementDefVecStruct;
};
  
struct Dims
{
    double x;
    double y;
   
    Dims(double x1, double y1) : x(x1), y(y1) {}
    Dims(double && x1, double && y1) : x(x1), y(y1) {}
    Dims() : x(0.0), y(0.0) {}
};


int main ()
{
  int num1 = 0.0, num2 = 0.00;
  int num3 = 0;
  
  num1 = 5;
  num2 = 6;

  num3 = 2;

  int numAns1 = num1%num3;
  int numAns2 = num2%num3;
  
  std::cout << std::endl << 5%2
            << "\t" << numAns1;

  double xIn = 0.0;
  double yIn = 0.0;

  Dims tempD(xIn,yIn);
  
  DefVecStruct<Dims> varVecStruct;

  std::cout << std::endl;
  std::cout << "\n Creating Vector with Struct as Elements .. \n \n";

  int* n = new int;
  
  std::cout << "\n Provide Number of Elements you would enter now: ";
  if (std::cin.get() == '\n')
  {
     std::cout << "Since skipped so the Default number of Elements (5) selected ... \n";
     *n = 2;
  }
  else 
     std::cin >> *n;

  std::cout << "\n \n \t .... Starting the lement entering in Vector process ... \n ";
  
  for(int i=0; i<*n; ++i)
  {
	std::cout << "\n Enter Element" << i << "Components : \n";
	std::cout << "Enter x: ";
   	std::cin >> xIn;
        std::cout << "\n Enter y: ";
   	std::cin >> yIn;
               
    	varVecStruct.push_back(Dims(xIn,yIn));
  }
 
  std::cout << "\n \n Vector Created .. here are the elements .... \n \n";
     
  return 0;

}
