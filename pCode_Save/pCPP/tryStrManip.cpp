#include <iostream>

int main ()
{
  std::string str;
  char ch = 'c';
  int n = 0;
 
  std::cout << std::endl << "Enter a string : ";
  std::getline(std::cin,str);

  std::cout << "\n" << "Good Work!" << "you enterd : " << str+ch << "\n";
  std::cout << "\n Lets see if that works : " << str[1] << std::endl;
  
  while ((str[n] != '\n') || (n < str.length()))
  {
    if (str[n] == ' ') std::cout << "This is the " << n+1 <<" Blane space \n";
    ++n;
  }

  return 0;
}
