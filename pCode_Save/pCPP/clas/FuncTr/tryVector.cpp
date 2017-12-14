#include <vector>
#include <string>
#include <iostream>

#include "Message.h"
#include "Message.cpp"

int main(int argc, char** argv)
{
	Message M1("The header of Now");
	Message M2("The header is here","The field is there");

	return 0;
}
