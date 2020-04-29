#include "declaration.h"
#include <cmath>

using namespace std;

/*** Methods of class Fraction ***/
ostream& operator<<(ostream& a, Fraction& b) {
    a << b.x << '/' << b.y;
    return a;
}
long long Fraction::gcd(long long a, long long b) {
    if (!b) return a;
    return gcd(b, a % b);
}
Fraction::Fraction(long long x, long long y) {
    if (this->x < 0 && this->y > 0 || this->x > 0 && this->y < 0) {
        this->sign = -1;
    }
    else {
        this->sign = 1;
    }
    this->x = abs(x);
    this->y = abs(y);
}
Fraction::Fraction(const Fraction& a) {
    this->x = a.x;
    this->y = a.y;
    this->sign = a.sign;
}
Fraction Fraction::operator+(const Fraction &a) {
    long long g = gcd(this->y, a.y);
    return Fraction(this->sign * this->x * (a.y / g) + a.sign * a.x * (this->y / g), this->y * (a.y / g));
}
Fraction& Fraction::operator=(const Fraction &a) {
    if (this == &a) {
        return *this;
    }
    this->x = a.x;
    this->y = a.y;
    this->sign = a.sign;
    return *this;
}
void Fraction::norm() {
    if (!this->x) {
        this->y = 1;
    }
    else {
        long long g = gcd(this->x, this->y);
        this->x /= g;
        this->y /= g;
    }
}


/***----------------------------------------------------***/


/*** Methods of class Egypt ***/
Egypt::Egypt(const Fraction& rat, long long n) {
    this->rat = rat;
    this->n = n;
    this->arr = new Fraction[n + 1];
    this->size = 0;
    start();
}

Fraction& Egypt::operator[](long long ind) {
    return this->arr[ind];
}

Egypt::Egypt(const Egypt& e) {
    this->rat = e.rat;
    this->size = e.size;
    this->n = e.n;
    this->arr = new Fraction[this->rat.x + 1];
    for (int i = 0; i < this->size; ++i) {
        this->arr[i] = e.arr[i];
    }
}

Egypt::~Egypt() {
    n = size = 0;
    delete[] arr;
}

Fraction& Egypt::getRational() {
    return this->rat;
}
long long Egypt::length() {
    return this->size;
}
void Egypt::start() {
    Fraction tmp = rat;
    tmp.norm();
    if (tmp.x == 0) {
        size = -1;
        return;
    }
    while (size < n) {
        arr[size++] = Fraction(1, ceil(1.0*tmp.y / tmp.x));
        if (tmp.y % tmp.x == 0) {
            break;
        }
        tmp = Fraction(tmp.x - (tmp.y % tmp.x), tmp.y * ceil(1.0*tmp.y / tmp.x));
        tmp.norm();
        if (size == n - 1) {
            arr[size++] = tmp;
        }
    }
}
ostream &operator<<(ostream &a, Egypt &ans) {
    if (ans.length() == -1) {
        a << "Impossible";
    }
    else {
        for (long long i = 0; i < ans.length() - 1; ++i) {
            a << ans[i] << " + ";
        }
        a << ans[ans.length() - 1];
    }
    return a;
}

Egypt &Egypt::operator=(const Egypt &e) {
    if (this == &e) {
        return *this;
    }
    this->rat = e.rat;
    this->size = e.size;
    this->n = e.n;
    this->arr = new Fraction[this->n + 1];
    for (int i = 0; i < this->size; ++i) {
        this->arr[i] = e.arr[i];
    }
    return *this;
}
