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

Racional::Racional(int num, int den){
	this -> num = num;
	this -> num = num;
	
}


const Racional& Racional::operator=(const Racional& r){
	num += r.num;
	den += r.den;
	return *this;
}

string Racional::toString() const{
	stringstream ss;
	if(den == 0 || den == 1){
		if (den == 0)
			ss << num;
		if (den == 1)
			ss << num;
	}else{
		ss << " " << num << " / " << den<< " " ;
	}
	return ss.str();
}


const Racional Racional::operator-() const{
   return Racional(-num, -den);
}

const Racional& Racional::operator+(const Racional& r){
   num + r.num;
   den + r.den;
   return *this;
}

const Racional& Racional::operator-(const Racional& r){
   return *this + -r;
}

ostream& operator<<(ostream& output, const Racional& c){
	if(c.den == 0 || c.den == 1){
		if (c.den == 0)
			output << c.num;
		if (c.den == 1)
			output << c.num;
	}else{
		output << " " << c.num << " / " << c.den<< " " ;
	}
	return output;
}
