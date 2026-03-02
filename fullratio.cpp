#include <iostream>
#ifndef CONTEST
#include "fullratio.hpp"
#endif

using namespace std;

int rational::gcd(int a, int b) {
    if (b == 0) return a;
    return gcd (b, a % b);
}

rational::rational (int n, int d) {
    nom = n;
    den = d;
}

rational operator + (const rational &x, const rational &y) {
    int n = x.nom * y.den + y.nom * x.den;
    int d = x.den * y.den;
    return rational((n/rational::gcd(n,d)), (d/rational::gcd(n,d)));
}

rational operator - (const rational &x, const rational &y) {
    int n = x.nom * y.den - y.nom * x.den;
    int d = x.den * y.den;
    return rational((n/rational::gcd(n,d)), (d/rational::gcd(n,d)));
}

rational operator * (const rational &x, const rational &y) {
    int n = x.nom * y.nom;
    int d = x.den * y.den;
    return rational((n/rational::gcd(n,d)), (d/rational::gcd(n,d)));
}

rational operator / (const rational &x, const rational &y) {
    int n = x.nom * y.den;
    int d = x.den * y.nom;
    return rational((n/rational::gcd(n,d)), (d/rational::gcd(n,d)));
}

ostream & operator << (ostream &out, const rational &x) {
    out << x.nom << "/" << x.den;
    return out;
}