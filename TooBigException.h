#pragma once
#include <iostream>
#include <string>

class TooBigException
	: public std::exception {
private:
	std::string message;
public:
	TooBigException();
	const char* what() const override;
};