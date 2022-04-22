#include "Hija.h"
#include <iostream>

Hija::Hija()
{
}

void Hija::Suma() 
{
	Padre::Suma();
	std::cout << 100 + 40 << std::endl;
}

void Hija::Resta()
{
	std::cout << 100 - 40 << std::endl;
}


