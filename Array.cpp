#include "Array.h"

Array::Array()
	: arr(nullptr), size(0) {}

Array::Array(int in_size) {
	if (in_size > max_size)
		throw OutOfRangeException(in_size, max_size);
	size = in_size;
	arr = new unsigned char[size];
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}

Array::Array(int in_size, unsigned char in_element) {
	if (in_size > max_size)
		throw OutOfRangeException(in_size, max_size);
	size = in_size;
	arr = new unsigned char[size];
	for (int i = 0; i < size; i++)
		arr[i] = in_element;
}

Array::Array(const Array& in_arr) {
	size = in_arr.size;
	arr = new unsigned char[size];
	for (int i = 0; i < size; i++)
		arr[i] = in_arr.arr[i];
}

Array::~Array() {
	delete[] arr;
}

int Array::get_size() const {
	return size;
}

void Array::clear() {
	for (int i = 0; i < size; i++)
		(*this)[i] = 0;
}

Array& Array::operator=(const Array& in_arr) {
	if (this == &in_arr)
		return *this;
	if (size != in_arr.size) {
		delete[] arr;
		size = in_arr.size;
		arr = new unsigned char[size];
	}
	for (int i = 0; i < size; i++) {
		arr[i] = in_arr.arr[i];
	}
	return (*this);
}

unsigned char& Array::operator[](int in_index) {
	if (in_index >= size)
		throw OutOfRangeException(in_index, size);
	return arr[in_index];
}

const unsigned char& Array::operator[](int in_index) const {
	if (in_index > size)
		throw OutOfRangeException(in_index, size);
	return arr[in_index];
}

void Array::add(const Array* in_arr) {
	if (in_arr->size != size)
		throw IncompatibleSizeException(in_arr->size, size);
	if (not in_arr)
		return;
	for (int i = 0; i < size; i++)
		this->arr[i] += in_arr->arr[i];
}

