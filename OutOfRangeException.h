#pragma once
#include <iostream>
#include <string>

class OutOfRangeException
	: public std::exception {
private:
	std::string message;
public:
	OutOfRangeException(int in_index, int in_size);
	const char* what() const override;
};