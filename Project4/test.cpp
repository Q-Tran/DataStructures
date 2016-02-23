// A2DD.cpp
#include <iostream>
#include <string>
#include "test.h"
A2DD::A2DD(int x,int y)
{
  gx = x;
  gy = y;
  name = "van";
}

int A2DD::getSum()
{
  return gx + gy;
}
std::string A2DD::getname(){
	return name;
}
int main(){
	std::cout << "eat a dick" << std::endl;
	A2DD z(1,2);
	std::cout << z.getSum() << endl << z.getname() << std::endl;
}