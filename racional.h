#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

class Racional{
	int  num, den;
public:
//	Racional(double, double);
	explicit Racional(int=0, int=1);
	string toString() const;
	int getNum();
	const Racional& operator=(const Racional&);
	const Racional operator-() const;
	const Racional& operator+=(const Racional&);
	const Racional& operator-=(const Racional&);
	const Racional& operator*=(const Racional&);
	const Racional inversa() const;
	friend ostream& operator<<(ostream&, const Racional&);
};
const Racional operator+(const Racional&, const Racional&);
const Racional operator-(const Racional&, const Racional&);
const Racional operator/(const Racional&, const Racional&);
const Racional operator*(const Racional&, const Racional&);

