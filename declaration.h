#ifndef DECLARATION_HEADER_H
#define DECLARATION_HEADER_H
#include <iostream>
class Fraction{
 public:
    long long x, y, sign;
    Fraction(long long x = 0, long long y = 1);
    Fraction(const Fraction& a);
    Fraction operator+(const Fraction &a);
    Fraction& operator=(const Fraction &a);
    long long gcd(long long a, long long b);
    void norm();
    friend std::ostream& operator<<(std::ostream& a, Fraction& b);
};

class Egypt{
 public:
    Fraction *arr;
    long long size, n;
    Fraction rat;
    Egypt(const Fraction& rat, long long n);
    Egypt(const Egypt& e);
    Egypt& operator=(const Egypt& e);
    Fraction& operator[](long long ind);
    void start();
    Fraction& getRational();
    long long length();
    virtual ~Egypt();
    friend std::ostream& operator<<(std::ostream &a, Egypt &ans);
};
#endif
