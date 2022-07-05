// FractionsExercise.cpp : This file contains the 'main' function. Here we do command line parsing

#include <iostream>
#include <string>

#include "Fraction.h"

int main()
{
	std::cout << "Command format: fraction1 operator fraction2. Example: 1/2 + 3/4. Type exit to quit the program." << std::endl;

	Fraction* fraction1 = new Fraction(0, 1);
	Fraction* fraction2 = new Fraction(0, 1);

	int n = 0;
	std::string op;

	while (true) 
	{		
		std::string s;  
		std::cin >> s;

		if (s == "exit") 
		{ 
			break;
		}
		if (n == 0)
		{
			fraction1 = new Fraction(s);
			if (fraction1->IsValid())
			{
				n++;
				continue;
			}
			else
			{
				std::cout << "Error in command format: fraction1 operator fraction2. Example: 2&3/8 + 9/8." << std::endl;
				n = 0;
				continue;
			}
		}
		if (n == 1)
		{
			if (s == "*" || s == "/" || s == "+" || s == "-")
			{
				op = s;
				n++;
				continue;
			}
			else
			{
				std::cout << "Error in command format: fraction1 operator fraction2. Example: 1/2 * 3&3/4." << std::endl;
				n = 0;
				continue;
			}
		}
		if (n == 2)
		{
			fraction2 = new Fraction(s);					
			try
			{
				Fraction res = calculate(*fraction1, *fraction2, op);
				std::cout << res << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what();
			}				
			n = 0;
			op = "";
			continue;		
		}
	}
}

