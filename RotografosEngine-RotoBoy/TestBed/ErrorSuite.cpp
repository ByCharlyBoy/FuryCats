#include "ErrorSuite.h"

char Pipop()
{
	int papas = 3;
	papas += 1;
	if (papas != 4) {
		return (char)Error1 | (char)Error2; //0000 0011
	}
	return (char)NoError;
}

void PrintError(char error)
{
	if (!error) {
		std::cout << "Todo chido carnal" << std::endl;
	}
	if (error & Error1) {
		std::cout << "Hijole, error 1" << std::endl;
	}
	if (error & Error2) {
		std::cout << "Hijole, error 2" << std::endl;
	}
}

