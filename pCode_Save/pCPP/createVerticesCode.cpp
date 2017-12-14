#include <iostream>
#include <vector>
#include <fstream>

struct Dims3D 
{
  double x;
  double y;
  double z;
  
  Dims3D(double x1, double y1, double z1) : x(x1), y(y1), z(z1) {}
  Dims3D() : x(0.0), y(0.0), z(0.0) {}
  
  void printDims3D()
  {
    std::cout << " (" << x << " " << y << " " << z << ") \n";
  }
 
  /*friend double operator<<(std::ostream out, Dims3D& D)
  {
	out << D.x << D.y << D.z;
  }*/ 
};



int main()
{
  int nVertices = 36;

  double Ex = 35.0, Ey = 45.0, Ez = 35.0;
  double Bx = 40.0, By = 10.0, Bz = 15.0;
  double Dx = 0.0, Dy = 15, Dz = 10;
  
  std::vector<Dims3D> blockVector (nVertices);
 /* 
  for (int i = 0; i<nVertices; ++i)
  {
    Dims3D blockTemp;
    blockVector.push_back(blockTemp);
  }*/

  for(int i=0; i<nVertices; i++)
  {  
     /* --- assigning All Y coordinates -----------------*/

     if((i>=2 && i<=5) || (i>=10 && i<=15) || (i>=20 && i<=25) || (i>=30 && i<=33))
	blockVector[i].y = Ey-Dy-By;
     else 
     {
	if (i%10==6 || i%10==7 || i==34 || i==35)
	  blockVector[i].y = Ey;
        else
    	  blockVector[i].y = 0;
     }

     if (i==4 || i==5 || (i>=13 && i<=15) || (i>=20 && i<=25) || i==32 || i==33)
	blockVector[i].y += By; 

     /* --- assigning All Z coordinates -----------------*/    

     if (i>=0 && i<=7) 
	blockVector[i].z = 0;
     else 
     {
	if (i>=8 && i<=17) 
	  blockVector[i].z = Dz; 
        else 
	{
	  if (i>=18 && i<=27) 
	   blockVector[i].z = Dz+Bz;
	else 
	   blockVector[i].z = Ez;
	}
     }

     /* --- assigning All X coordinates -----------------*/ 

     ( i % 2 == 0) ? blockVector[i].x=0 : blockVector[i].x=Ex;

     if (i==12 || i==15 || i==22 || i==25)
 	blockVector[i].x = Ex+Bx;
     else 
     {
	if (i==14)
 	  blockVector[i].x = Ex;
     }
  }
  
 std::cout << "\n \n ...showing vector ... \n \n ";
 int count = 0; 
 

 for(std::vector<Dims3D>::iterator j = blockVector.begin(); j != blockVector.end(); ++j)
 {
    	//std::cout << "\t"; //++count;
	j->printDims3D();
	//std::cout << "\n (" <<*j.x <<"," << *j.y << "," << *j.z << ")";
 }

  return 0; 
}
