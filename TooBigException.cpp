#include "TooBigException.h"

TooBigException::TooBigException() {
	message.assign("Numbers are too big.");
}

const char* TooBigException::what() const {
	return message.c_str();
}