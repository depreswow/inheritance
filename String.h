#pragma once
#include "Array.h"

class String 
	: public Array {
public:
	String();
	explicit String(int in_size);

	const unsigned char& length() const;

	int find(const String& in_string) const; //возвращает индекс первого вхождения подстроки, или 0, если вхождение не найдено
	bool remove(const String& in_string); //true - подстрока удалена, false - подстрока не найдена
	bool insert(const String& in_string, int in_index); //true - подстрока вставлена, false - места не хватает
	bool join(const String& in_string); //true - удалось объеднить, false - места не хватает

	friend std::istream& operator>>(std::istream& in, String& in_string);
	friend std::ostream& operator<<(std::ostream& out, const String& in_string);


	void add(const Array* in_string) override;
};