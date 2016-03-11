#include "racional.h"
#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::stringstream;
using std::ostream;
using std::istream;
using std::showpos;
using std::noshowpos;

Racional::Racional(int num, int den):num(num), den(den){
	if(den<0){
		num *= -1;
	}
	if(den<0 && num<0){
		den *= -1;
		num *= -1;
	}
	int menor = num;
	if(menor>den){
		menor = num;
	}
	for (int i = 2; i < menor; i++){
		if(num%i==0 && den%2==0){
			num = num%i;
			den = den%i;
		}
	}
}


const Racional& Racional::operator=(const Racional& r){
	num = r.num;
	den = r.den;
	return *this;
}

string Racional::toString() const{
	stringstream ss;
	ss << " " <<num << " / " << den<< " " ;
	return ss.str();
}

const Racional operator+(const Racional& lhs, const Racional& rhs){
	Racional retVal = lhs;
	retVal += rhs;
	return retVal;
}

const Racional operator-(const Racional& lhs, const Racional& rhs){
	Racional retVal = lhs;
	retVal -= rhs;
	return retVal;
}

const Racional Racional::operator-() const{
   return Racional(-num, -den);
}

const Racional& Racional::operator+=(const Racional& r){
   num += r.num;
   den += r.den;
   return *this;
}

const Racional& Racional::operator-=(const Racional& r){
   return *this += -r;
}

ostream& operator<<(ostream& output, const Racional& c){
	if(c.den == 0 || c.den == 1){
		if (c.den == 0)
			output << c.num;
		if (c.den == 1)
			output << c.num;
	}else{
		output << c.toString();
	}
	return output;
}
