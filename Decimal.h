#pragma once
#include "Array.h"
#include "TooBigException.h"

class Decimal
	: public Array {
private:
	bool sign; //true - положительное, false - отрицательное
public:
	Decimal();
	explicit Decimal(int in_number);

	Decimal& operator=(int in_number);

	Decimal operator-() const;
	
	Decimal operator+(const Decimal& in_decimal) const;
	Decimal operator-(const Decimal& in_decimal) const;

	Decimal operator*(const Decimal& in_decimal) const;

	bool operator>(const Decimal& in_decimal) const;
	bool operator<(const Decimal& in_decimal) const;

	bool operator>=(const Decimal& in_decimal) const;
	bool operator<=(const Decimal& in_decimal) const;

	bool operator==(const Decimal& in_decimal) const;

	friend std::istream& operator>>(std::istream& in, Decimal& in_decimal);
	friend std::ostream& operator<<(std::ostream& out, const Decimal& in_decimal);

	void add(const Array* in_arr) override;
};