#pragma once
#include <iostream>
#include <string>

class IncompatibleSizeException
	: public std::exception {
private:
	std::string message;
public:
	IncompatibleSizeException(int in_size_1, int in_size_2);
	const char* what() const override;
};