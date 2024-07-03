#include "Decimal.h"

Decimal::Decimal() 
	: Array(100), sign(true) {
}

Decimal::Decimal(int in_number)
	: Array(100), sign(in_number >= 0) {
	for (int i = 0; in_number != 0; i++) {
		(*this)[i] = in_number % 10;
		in_number /= 10;
	}
}

Decimal& Decimal::operator=(int in_number) {
	clear();
	for (int i = 0; in_number != 0; i++) {
		(*this)[i] = (in_number % 10) + '0';
		in_number /= 10;
	}
	return (*this);
}

Decimal Decimal::operator-() const {
	Decimal buffer(*this);
	buffer.sign = not buffer.sign;
	return buffer;
}

Decimal Decimal::operator+(const Decimal& in_decimal) const {
	if ((sign && in_decimal.sign) || (not sign && not in_decimal.sign)) {
		if ((*this)[99] + in_decimal[99] >= 8)
			throw TooBigException();
		Decimal buffer(*this);
		for (int i = 0; i < 100; i++) {
			buffer[i] += in_decimal[i];
			if (buffer[i] > 9) {
				buffer[i] -= 10;
				buffer[i + 1]++;
			}
		}
		return buffer;
	}
	else if ((sign && ((*this) >= (-in_decimal))) || ((not sign) && (-(*this) > in_decimal))) {
			Decimal buffer(*this);
			for (int i = 0; i < 100; i++) {
				buffer[i] -= in_decimal[i];
				if (buffer[i] < 0) {
					buffer[i] += 10;
					buffer[i + 1]--;
				}
			}
			return buffer;
		}
	else {
		Decimal buffer(in_decimal);
		for (int i = 0; i < 100; i++) {
			buffer[i] -= (*this)[i];
			if (buffer[i] > 9) {
				buffer[i] += 10;
				buffer[i + 1]--;
			}
		}
		return buffer;
	}
}

Decimal Decimal::operator-(const Decimal& in_decimal) const {
	return (*this) + -in_decimal;
}

Decimal Decimal::operator*(const Decimal& in_decimal) const {
	int size_1=0, size_2=0;
	for (int i = 99; i >= 0; i--) {
		if (size_1 == 0 && (*this)[i] != 0)
			size_1 = i + 1;
		if (size_2 == 0 && (*this)[i] != 0)
			size_2 = i + 1;
	}
	if (size_1 + size_2 > 100)
		throw TooBigException();
	Decimal buffer(0);
	if ((sign && in_decimal.sign) || (not sign && not in_decimal.sign))
		buffer.sign = true;
	else
		buffer.sign = false;
	int sum_buffer;
	for (int i = 0; i <= size_2; i++) {
		sum_buffer = 0;
		for (int j = 0; j < size_1; j++) {
			buffer[i+j] += (*this)[j] * in_decimal[i] + sum_buffer;
			sum_buffer = buffer[i+j] / 10;
			buffer[i+j] %= 10;
		}
	}
	return buffer;
}

bool Decimal::operator>(const Decimal& in_decimal) const {
	for (int i = 99; i >= 0; i--) {
		if ((*this)[i] > in_decimal[i])
			return true;
		if ((*this)[i] < in_decimal[i])
			return false;
	}
	return false;
}

bool Decimal::operator<(const Decimal& in_decimal) const {
	for (int i = 99; i >= 0; i--) {
		if ((*this)[i] < in_decimal[i])
			return true;
		if ((*this)[i] > in_decimal[i])
			return false;
	}
	return false;
}

bool Decimal::operator>=(const Decimal& in_decimal) const {
	for (int i = 99; i >= 0; i--) {
		if ((*this)[i] > in_decimal[i])
			return true;
		if ((*this)[i] < in_decimal[i])
			return false;
	}
	return true;
}

bool Decimal::operator<=(const Decimal& in_decimal) const {
	for (int i = 99; i >= 0; i--) {
		if ((*this)[i] < in_decimal[i])
			return true;
		if ((*this)[i] > in_decimal[i])
			return false;
	}
	return true;
}

bool Decimal::operator==(const Decimal& in_decimal) const {
	for (int i = 99; i >= 0; i--) {
		if ((*this)[i] != in_decimal[i])
			return false;
	}
	return true;
}

std::istream& operator>>(std::istream& in, Decimal& in_decimal) {
	std::cout << "Enter a decimal" << std::endl;
	int n;
	in >> n;
	in_decimal.clear();
	for (int i = 0; n != 0; i++) {
		in_decimal[i] = (n % 10);
		n /= 10;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Decimal& in_decimal) {
	if (not in_decimal.sign)
		out << '-';
	for (int i = 0; i < 100; i++)
		out << (int)in_decimal[i];
	return out;
}

void Decimal::add(const Array* in_arr) {
	const Decimal* in_decimal = dynamic_cast<const Decimal*>(in_arr);
	if (not in_decimal)
		return;
	(*this) = (*this) + (*in_decimal);
}