#pragma once
#include <iostream>

enum ErrorCode {
	NoError = 0x00,
	Error1 = 0x01, //0000 0001
	Error2 = 0x02, //0000 0010
	Error3 = 0x04, 
	Error4 = 0x08,
	Error5 = 0x10,
	Error6 = 0x20,
	Error7 = 0x40,
	Error8 = 0x80
};



char Pipop();

void PrintError(char error);
