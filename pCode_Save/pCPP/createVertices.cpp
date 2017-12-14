#include <iostream>
#include <vector>

void drawAxes();

template <typename CoordinateType>
struct DimenStruct 
{
	CoordinateType X;
	CoordinateType Y;
   	CoordinateType Z;
};

/**************************** MAIN STARTS HERE **************************************
*************************************************************************************/

int main ()
{

  struct Dim 
  {
	double lengthX = 0.0;
	double lengthY = 0.0;
  	double lengthZ = 0.0;
  };

  //DimenStruct <double> CoordCell;
  
  // std::vector<Dim> CellArray;
  Dim CellArray[36];

  Dim LocationBlowerFace;
  Dim EvapTop;
  Dim BlowerOut; 
 
  Dim DeltaMesh;
  Dim DeltaCell; 
 
  drawAxes();

  std::cout << std::endl << "Enter Dimensions of Evaporator Top Duct \n \n"
	    << " X direction: " ;
  if (std::cin.get() == '\n')
  {
        EvapTop.lengthX = 25;
	std::cout << "\n Default X value 25 taken .. now enter next ... \n";
  }
  else
     	std::cin >> EvapTop.lengthX;

 
  std::cout << std::endl << "\n Y direction: " ;
  if (std::cin.get() == '\n')
  {
	EvaoTop.lengthY = 35;
	std::cout << "\n Default Y direction value of 35 is set.. next  ... \n ": 
  }
  else
	std::cin >> EvapTop.lengthY;

  std::cout << std::endl << "\n Z direction: " ;
  std::cin >> EvapTop.lengthZ;

  std::cout << std::endl;

  std::cout << std::endl << "Enter Dimensions of Blower Outlet Duct \n \n"
	    << " X direction: " ;
  std::cin >> BlowerOut.lengthX;
 
  std::cout << std::endl << "\n Y direction: " ;
  std::cin >> BlowerOut.lengthY;

  std::cout << std::endl << "\n Z direction: " ;
  std::cin >> BlowerOut.lengthZ;

  std::cout << std::endl << "Enter Location of Blower Outlet o Evap Top Duct \n"
	    << " Distance from Left Edge: " ;
  std::cin >> LocationBlowerFace.lengthZ;
 
  std::cout << std::endl << "\n Distance from Top Edge: " ;
  std::cin >> LocationBlowerFace.lengthY;

  LocationBlowerFace.lengthX = EvapTop.lengthX;

  
  std::cout << "\n Defining the Blocks for Generating Vertices ... \n";
  
  DeltaCell.lengthX = 0.0;
  DeltaCell.lengthY = EvapTop.lengthY-BlowerOut.lengthY-LocationBlowerFace.lengthY;
  DeltaCell.lengthZ = EvapTop.lengthZ-BlowerOut.lengthZ-LocationBlowerFace.lengthZ;
  
  Dim tempD;

  int Bit0 = 0, Bit1 = 0, Bit2 = 0,  Bit3 = 0;

  for (int i=0; i<=7; ++i)
  {
     CellArray[i].lengthZ = 0.0;

     switch ( ((i<2)?Bit0=0:0) |((i>=2 && i<4)?Bit0=1:0) | ((i>=4 && i<6)?Bit0=3:0) | ((i>=6 && i<8)?Bit0=4:0) )
     {
	   case 0: CellArray[i].lengthY = 0.0; 
			break;
           case 1: CellArray[i].lengthY = DeltaCell.lengthY; 
			break;
	   case 2: CellArray[i].lengthY = LocationBlowerFace.lengthY;
			break;
	   case 3: CellArray[i].lengthY = EvapTop.lengthY;
			break;
     }
     
     (i%2) ? CellArray[i].lengthX = 0.0 : CellArray[i].lengthX = EvapTop.lengthX;

  }

  /*for(int i=8; i<=17; ++i)
  {
     CellArray[i].lengthZ = LocationBlowerFace.lengthZ;

     switch (i) 
     {
	   case  8 ||  9: CellArray[i].lengthY = 0.0; 
			  break;
           case 10 || 11: CellArray[i].lengthY = DeltaCell.lengthY; 
			  break;
	   case 12 || 15: CellArray[i].lengthY = EvapOut.lengthY+ BlowerOut.lengthY;
			  break;
	   case 13 || 14: CellArray[i].lengthY = LocationBlowerFace.lengthY;
			  break;
	   case 16 || 17: CellArray[i].lengthY = EvapOut.lengthY;
			  break;
     }
  }*/
  for(int i=18; i<=27; ++i)
     CellArray[i].lengthZ = LocationBlowerFace.lengthZ + BlowerOut.lengthZ;
  for(int i=28; i<=35; ++i) 
     CellArray[i].lengthZ = EvapTop.lengthZ;
 
  
  	
  return 0;
}


void printVertices()
{
}

void drawAxes()
{
  using namespace std;
  
  cout << endl << "\n Cartesian Cordinate System ..........." << " ^ Y" << "\n";
  
  for(int x=0;x<5;++x)
  cout << " :" << endl;
  for(int y=0; y < 8; ++y)
  cout << " .." ;
  cout << " > X " << endl;
  for(int z=1; z<6; ++z)
  {    
    for(int temp_z=0;temp_z<z;++temp_z)
      cout << " ";
    if (z == 5)
      cout << "\\/ Z";
    else
      cout << " \\" << endl;
  }
}  


