#ifndef CONTEST
#include "babyratio.hpp"
#include <iostream>
#endif

using namespace std;

int rational::gcd (int a, int b) {
    if (b == 0) return a;
    return gcd (b, a % b);
}

rational::rational (int n, int d) {
    if (n < 0 && d < 0) {
        nom = -n / gcd (-n, -d);
        den = -d / gcd (-n, -d);
    }
    else if (d<0 && n>=0) {
        nom = -n / gcd (n,-d);
        den = -d / gcd (n,-d);
    }
}

rational rational::add (rational r) {
    int n = nom * r.den + r.nom * den;
    int d = den * r.den;
    n /= gcd (n, d);
    d /= gcd (n, d);
    return rational (n, d);
}

rational rational::sub (rational r) {
    int n = nom * r.den - r.nom * den;
    int d = den * r.den;
    n /= gcd (n, d);
    d /= gcd (n, d);
    return rational (n, d);
}   

rational rational::mul (rational r) {
    int n = nom * r.nom;
    int d = den * r.den;
    n /= gcd (n, d);
    d /= gcd (n, d);
    return rational (n, d);
}

rational rational::div (rational r) {
    int n = nom * r.den;
    int d = den * r.nom;
    n /= gcd (n, d);
    d /= gcd (n, d);
    return rational (n, d);
}

void rational::print () {
    cout << nom << "/" << den;
}
