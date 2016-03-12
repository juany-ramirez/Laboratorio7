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
	if(den<0 && num<0){
		den *=-1;
		num *= -1;
	}
	if(den<0){
		num *= -1;
		den *= -1;
	}
	if(den==0){
		den =1;
	}
	int menor = num;
	if(menor<den){
		menor = den;
	}
	for (int i = 2; i < menor; i++){
		if((num%i==0) && (den%i==0)){
			num = num/i;
			den = den/i;
		}
	}
	this -> num = num;
	this -> den = den;
	
}

int Racional::getNum() {
	return num;
}

string Racional::toString() const{
	stringstream ss;
	if(den == 0 || den == 1 || num ==0){
		ss << num;
	}else{
		ss << " " << num << " / " << den<< " " ;
	}
	return ss.str();
}

const Racional& Racional::operator=(const Racional& r){
	num = r.num;
	den = r.den;
	if(den<0 && num<0){
		den *=-1;
		num *= -1;
	}
	if(den<0){
		num *= -1;
		den *= -1;
	}
	if(den==0){
		den =1;
	}
	int menor = num;
	if(menor<den){
		menor = den;
	}
	for (int i = 2; i < menor; i++){
		if((num%i==0) && (den%i==0)){
			num = num/i;
			den = den/i;
		}
	}
	return *this;
}


const Racional Racional::operator-() const{
   return Racional(-num, -den);
}

const Racional& Racional::operator+=(const Racional& b){
   num = (num*b.den)+(b.num*den);
   den = den*b.den;
   if(den<0 && num<0){
		den *=-1;
		num *= -1;
	}
	if(den<0){
		num *= -1;
		den *= -1;
	}
	if(den==0){
		den =1;
	}
	int menor = num;
	if(menor<den){
		menor = den;
	}
	for (int i = 2; i < menor; i++){
		if((num%i==0) && (den%i==0)){
			num = num/i;
			den = den/i;
		}
	}
   return *this;
}

const Racional& Racional::operator-=(const Racional& r){
   return *this += -r;
}

//return new Fraccion(a.den, a.num);
const Racional Racional::inversa() const{
	return Racional(den, num);
}

const Racional& Racional::operator*=(const Racional& b){
	num= num*b.num;
    den= den*b.den;
    if(den<0 && num<0){
		den *=-1;
		num *= -1;
	}
	if(den<0){
		num *= -1;
		den *= -1;
	}
	if(den==0){
		den =1;
	}
	int menor = num;
	if(menor<den){
		menor = den;
	}
	for (int i = 2; i < menor; i++){
		if((num%i==0) && (den%i==0)){
			num = num/i;
			den = den/i;
		}
	}
	return *this;
}

ostream& operator<<(ostream& output, const Racional& c){
	if(c.den == 0 || c.den == 1 || c.num == 0){
		if (c.den == 0)
			output << c.num;
		if (c.den == 1)
			output << c.num;
	}else{
		output << " " << c.num << " / " << c.den<< " " ;
	}
	return output;
}

const Racional operator+(const Racional& rd, const Racional& hp){
	Racional retVal=rd;
	retVal += hp;
	return retVal;
}

const Racional operator-(const Racional& rd, const Racional& hp){
	Racional retVal=rd;
	retVal -= hp;
	return retVal;
}

const Racional operator/(const Racional& rd, const Racional& hp){
	Racional retVal=rd;
	retVal *= hp.inversa();
	return retVal;
}

const Racional operator*(const Racional& rd, const Racional& hp){
	Racional retVal=rd;
	retVal *= hp;
	return retVal;
}

