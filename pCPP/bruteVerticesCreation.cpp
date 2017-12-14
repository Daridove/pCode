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
    std::cout << " (" << x <<"," << y << "," << z << ") \n";
  }
 
  /*friend double operator<<(std::ostream out, Dims3D& D)
  {
	out << D.x << D.y << D.z;
  }*/ 
};



int main()
{
  int nVertices = 36;

  double Ex = 25.0, Ey = 35.0, Ez = 25.0;
  double Bx = 40.0, By = 10.0, Bz = 15.0;
  double Dx = 0.0, Dy = 15, Dz = 10;
  
  std::vector<Dims3D> blockVector (nVertices);
 
 std::cout << "\n \n ...showing vector ... \n \n ";
 int count = 0; 
 

 for(std::vector<Dims3D>::iterator j = blockVector.begin(); j != blockVector.end(); ++j)
 {
    	std::cout << ++count;
	j->printDims3D();
	//std::cout << "\n (" <<*j.x <<"," << *j.y << "," << *j.z << ")";
 }

  return 0; 
}
