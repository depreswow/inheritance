#pragma once
#include <iostream>
#include "Decimal.h"
#include "String.h"

class Application {
private:
	Array* arr_1;
	Array* arr_2;
public:
	Application();
	~Application();

	void Run();
	void Run_String();
	void Run_Decimal();
};