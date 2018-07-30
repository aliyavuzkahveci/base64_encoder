// Base64.cpp : Defines the entry point for the console application.
//

#include "Base64.h"

#include <iostream>

constexpr auto HELP = "-h";
constexpr auto ENCODE = "-e";
constexpr auto DECODE = "-d";

constexpr auto UC_Q = 0x51;
constexpr auto LC_Q = 0x71;

int main(int argc, char* argv[])
{
	int returnValue = 0;
	bool isEncode = false;

	if (argc == 2 && std::strcmp(argv[1], HELP) == 0)
	{
		returnValue = 1; //HELP requested!
	}
	else if (argc == 3 && std::strcmp(argv[1], ENCODE) == 0)
	{
		isEncode = true;
	}
	else if (argc == 3 && std::strcmp(argv[1], DECODE) == 0)
	{
		isEncode = false;
	}
	else
	{
		std::cout << "You have entered wrong inputs..." << std::endl;
		returnValue = -1;
	}


	if (returnValue != 0)
	{
		std::cout << "There 2 formats for the correct execution of the program:" << std::endl;
		std::cout << "	1. Base64.exe -e ~plainString~" << std::endl;
		std::cout << "	2. Base64.exe -d ~encodedString~" << std::endl;
	}
	else //Starting the execution of the real program!
	{
		std::string output;
		if (isEncode)
		{
			output = Base64::Encode((const unsigned char*)argv[2], strlen(argv[2]));
			std::cout << "Encoded ";
		}
		else
		{
			output = Base64::Decode(std::string(argv[2]));
			std::cout << "Decoded ";
		}

		std::cout << "Output: " << output << std::endl;
	}


    return returnValue;
}

