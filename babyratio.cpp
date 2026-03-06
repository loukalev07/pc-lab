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
    if (n < 0 && d < 0) {
        nom = -n / gcd (-n, -d);
        den = -d / gcd (-n, -d);
    }
    else if (d<0 && n>=0) {
        nom = -n / gcd (n,-d);
        den = -d / gcd (n,-d);
    }
    else {
        nom = n / gcd (abs(n), d);
        den = d / gcd (abs(n), d);
    }
}

rational rational::add (rational r) {
    nom = nom * r.den + r.nom * den;
    den = den * r.den;
    int n = nom / gcd (abs(nom), den);
    int d = den / gcd (abs(nom), den);
    return rational (n, d);
}

rational rational::sub (rational r) {
    nom = nom * r.den - r.nom * den;
    den = den * r.den;
    int n = nom / gcd (abs(nom), den);
    int d = den / gcd (abs(nom), den);
    return rational (n, d);
}   

rational rational::mul (rational r) {
    nom = nom * r.nom;
    den = den * r.den;
    int n = nom / gcd (abs(nom), den);
    int d = den / gcd (abs(nom), den);
    return rational (n, d);
}

rational rational::div (rational r) {
    nom = nom * r.den;
    den = den * r.nom;
    int n = nom / gcd (abs(nom), den);
    int d = den / gcd (abs(nom), den);
    return rational (n, d);
}

void rational::print () {
    cout << nom << "/" << den;
}
