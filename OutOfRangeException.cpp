#include "OutOfRangeException.h"

OutOfRangeException::OutOfRangeException(int in_index, int in_size) {
	message.assign("Out of range exception.\nIndex = " + std::to_string(in_index) + ", Size = " + std::to_string(in_size));
}

const char* OutOfRangeException::what() const {
	return message.c_str();
}