#ifndef CONTEST
#include "babyratio.hpp"
#include <iostream>
#endif

using namespace std;

int rational::gcd (int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) a = a % b; else b = b % a;
    }
    return(a+b);
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

rational rational::add (rational r) {
    int n = nom * r.den + r.nom * den;
    int d = den * r.den;
    return rational (n, d);
}

rational rational::sub (rational r) {
    int n = nom * r.den - r.nom * den;
    int d = den * r.den;
    return rational (n, d);
}   

rational rational::mul (rational r) {
    int n = nom * r.nom;
    int d = den * r.den;
    return rational (n, d);
}

rational rational::div (rational r) {
    int n = nom * r.den;
    int d = den * r.nom;
    return rational (n, d);
}

void rational::print () {
    cout << nom << "/" << den;
}
