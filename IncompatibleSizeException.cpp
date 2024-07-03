#include "IncompatibleSizeException.h"

IncompatibleSizeException::IncompatibleSizeException(int in_size_1, int in_size_2) {
	message.assign("Incompatible size exception.\nSize 1 = " + std::to_string(in_size_1) + ", Size 2 = " + std::to_string(in_size_2));
}

const char* IncompatibleSizeException::what() const {
	return message.c_str();
}