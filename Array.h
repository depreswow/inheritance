#pragma once
#include <iostream>
#include "OutOfRangeException.h"
#include "IncompatibleSizeException.h"

class Array {
private:
	unsigned char* arr;
	int size;
	static const int max_size=255;
public:
	Array();
	explicit Array(int in_size);
	explicit Array(int in_size, unsigned char in_element);
	Array(const Array& in_arr);
	virtual ~Array();

	int get_size() const;

	void clear();

	Array& operator=(const Array& in_arr);

	unsigned char& operator[](int in_index);
	const unsigned char& operator[](int in_index) const;

	virtual void add(const Array* in_arr);
};