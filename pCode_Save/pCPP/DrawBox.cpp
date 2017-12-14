#include <iostream>
#include <cmath>

void makeDuctImage()
{
  using namespace std;
  int dirX = 20;
  int dirY = 12;
  int dirZ = 10;

  cout << endl;
  for (int iX =0; iX<dirX; ++iX)
   cout << "*";
  
  cout <<  endl;
  
  for (int iY = 0; iY<dirY-2; ++iY)
  {
    cout << "*";
    for(int temp_Y=0; temp_Y < iY; ++temp_Y)
	cout << " ";
    cout << "*" ;
    for (int temp_X=0; temp_X < dirX-iY-3; ++temp_X)
    	cout << " ";
    cout << "*";
    for (int temp_Y=0; temp_Y<iY; ++temp_Y)
	cout << " ";
    cout << "*"  << endl;
  }  

  for(int iX = 0; iX<dirX; ++iX)
   cout << "*";

  cout << endl;

  for(int iY = 0; iY < dirY-2; ++iY)
  {
    int lenY = dirY-2;
 
    for(int temp_Y=0;temp_Y<lenY;++temp_Y)
	cout  << " ";
    for(int iX=0; iX<dirX-iY; ++iX)
	cout << " ";
    cout << "*";
    for(int temp_Y=0;temp_Y<dirX;++temp_Y)
  	cout << " ";
    cout << "*" ;
    for( int temp_Z=0; temp_Z<iY; ++temp_Z)
    	cout << " ";
    cout << "*" << endl;
  } 

}
int main ()
{
  double deltaX = 0.0;
  double deltaY = 0.0;
  double deltaZ = 0.0;

  double lengthX = 0.0;
  double lengthY = 0.0;
  double lengthZ = 0.0;

  double desired_deltaX = 0.0;
  double desired_deltaY = 0.0;
  double desired_deltaZ = 0.0;

  //std::cout << std::endl << "Enter length of the x : " ;
  //std::cin >> lengthX;
 
  makeDuctImage();

 return 0;
}
