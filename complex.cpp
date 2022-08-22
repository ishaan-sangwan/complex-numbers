#include <iostream>
#include "complex.h"
#include <cmath>

using namespace std;

const double complex::magnitude(){
    return sqrt(real*real + imagine*imagine);
}

const double complex::arg(){
    return atan(iamgine/real);
}

const complex complex::conj(){
    imagine = -imagine;
}

const complex complex::operator=(const complex & rhs){
    real= rhs.real;
    imagine =rhs.imagine;
    return *this
}

const complex complex::operator+=(const complex & rhs){
    real += rhs.real;
    imagine += rhs.imagine;
    return *this;
}

const complex complex::operator-=(const complex & rhs){
    real -= rhs.real;
    imagine -= rhs.imagine;
    return *this;
}

const complex complex::operator *=(const complex & rhs){
    real  = real*rhs.real - imagine*rhs.imagine;
    imagine = real*rhs.imagine + rhs.real*imagine;
    return *this;
}


complex complex::operator+(const complex & rhs)const{
    complex temp(*this);
    temp += rhs;
    return temp;
}

complex complex::operator-(const complex & rhs) const{
    complex temp(*this);
    temp -= rhs;
    return temp;
}

complex complex::operator*(const complex & rhs) const{
    complex temp(*this);
    temp *= rhs;
    return temp
}

const complex complex::operator /=(const complex & rhs){
    real = ((*this*rhs.conj()).Re())/(rhs.maginitude()* rhs.magnitude());
    imagine = ((*this*rhs.conj()).Im())/(rhs.maginitude()* rhs.magnitude());
    return *this;
}

complex complex::operator/(const complex & rhs){
    complex temp(*this);
    temp /= rhs;
    return *this;
}

bool complex::operator == (const complex & rhs)const{
    return real==rhs.real && imagine==rhs.imagine;
}

bool complex::operator != (const complex & rhs) const{
    return !(real==rhs.real && imagine==rhs.imagine);
}

complex::operator-()const{
        return complex(-real, -imagine);
}

complex::istream & operator>>(istream & in, complex & cmp){
    in >> cmp.real;
    cmp.imagine =1;
    char ch;
    in.get(ch);
    if (!in.eof()){
        if (ch=="i"){
            in>>cmp.imagine;
        }
        else in.putback(ch);
    }
    return in;
}

complex::ostream & operator<<(istream & out, complex & cmp){
    out<<cmp.real<<" +i"cmp.imagine;
}