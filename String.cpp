#include "String.h"

String::String() 
	: Array(255) {}

String::String(int in_size) 
	: Array(255) {
	if (in_size >= 255)
		throw OutOfRangeException(in_size, 254);
	(*this)[0] = in_size;
}

const unsigned char& String::length() const {
	return (*this)[0];
}

int String::find(const String& in_string) const {
	if (this->length() < in_string.length())
		return 0;
	int substring_char_counter=0;
	for (int i = 1; i <= length(); i++) {
		if ((*this)[i] == in_string[substring_char_counter + 1])
			substring_char_counter++;
		else
			substring_char_counter = 0;
		if (substring_char_counter == in_string.length())
			return i-substring_char_counter+1;
	}
	return 0;
}

bool String::remove(const String& in_string) {
	int substring_index = (*this).find(in_string);
	if (substring_index == 0)
		return false;
	for (int i = substring_index; i <= length()-in_string.length(); i++) //ae
		(*this)[i] = (*this)[i + in_string.length()];
	for (int i = length() - in_string.length() + 1; i <= length(); i++)
		(*this)[i] = 0;
	(*this)[0] -= (in_string.length());
	return true;
}

bool String::insert(const String& in_string, int in_index) {
	if ((in_index == 0) 
		|| (length() + in_string.length() >= 255) 
		|| (in_index + in_string.length() - 1 > 255)
		|| (in_index>length()))
		return false;
	for (int i = in_index; i < length() + in_string.length(); i++) {
		(*this)[i + in_string.length()] = (*this)[i];
		(*this)[i] = in_string[i - in_index + 1];
	}
	(*this)[0] += in_string.length();
	return true;
}

bool String::join(const String& in_string) {
	if (length() + in_string.length() >= 255)
		return false;
	for (int i = length() + 1; i <= length() + in_string.length(); i++)
		(*this)[i] = in_string[i - length()];
	(*this)[0] += in_string.length();
	return true;
}

std::istream& operator>>(std::istream& in, String& in_string) {
	std::cout << "Enter size of the string:" << std::endl;
	int size;
	std::cin >> size;
	if (size > 255)
		throw OutOfRangeException(size, 255);
	in_string[0] = size;
	std::cout << "Enter string:" << std::endl;
	for (int i = 1; i <= in_string.length(); i++)
		in >> in_string[i];
	return in;
}

std::ostream& operator<<(std::ostream& out, const String& in_string) {
	for (int i = 1; i <= in_string.length(); i++)
		out << in_string[i];
	return out;
}

void String::add(const Array* in_arr) {
	const String* in_string = dynamic_cast<const String*>(in_arr);
	if (not in_string)
		return;
	if (in_string->length() != length())
		throw IncompatibleSizeException(length(), in_string->length());
	for (int i = 1; i <= length(); i++)
		(*this)[i] = ((*this)[i] + (*in_string)[i]) % 25 + 'a';
}