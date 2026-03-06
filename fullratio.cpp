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
    int Gcd = gcd(abs(n), abs(d));
    n = n / Gcd;
    d = d / Gcd;

    if (n < 0 && d < 0) {
        nom = -n;
        den = -d;
    }
    else if (d<0 && n>=0) {
        nom = -n;
        den = -d;
    }
    else {
        nom = n;
        den = d;
    }
}

rational operator + (const rational &x, const rational &y) {
    int n = x.nom * y.den + y.nom * x.den;
    int d = x.den * y.den;
    return rational(n, d);
}

rational operator - (const rational &x, const rational &y) {
    int n = x.nom * y.den - y.nom * x.den;
    int d = x.den * y.den;
    return rational(n,d);
}

rational operator * (const rational &x, const rational &y) {
    int n = x.nom * y.nom;
    int d = x.den * y.den;
    return rational(n,d);
}

rational operator / (const rational &x, const rational &y) {
    int n = x.nom * y.den;
    int d = x.den * y.nom;
    return rational(n,d);
}

ostream & operator << (ostream &out, const rational &x) {
    out << x.nom << "/" << x.den;
    return out;
}
