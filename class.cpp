#include <iostream>
#include <algorithm>
using namespace std;

int NOD(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    while (a % b != 0) {
        a = a % b;
        swap(a, b);
    }
    return b;
}

class Rational {
private:
    int numerator;
    int denominator;
public:
    Rational(int num, int den) : numerator(num), denominator(den) {}

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }

    void set(int num, int den) {
        numerator = num;
        denominator = den;
    }

    void reduce() {
        int gcd = NOD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    bool equals(const Rational& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    Rational operator+(const Rational& other) const {
        return Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Rational operator-(const Rational& other) const {
        return Rational(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Rational operator*(const Rational& other) const {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    Rational operator/(const Rational& other) const {
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }
};

int main() {
    Rational r1(2, 3);
    Rational r2(3, 4);

    cout << "r1: ";
    r1.print();
    cout << "r2: ";
    r2.print();

    r1.set(4, 6);
    cout << "r1 after set: ";
    r1.print();

    r1.reduce();
    cout << "r1 after reduce: ";
    r1.print();

    cout << "r1 equals r2: " << r1.equals(r2) << endl;

    Rational r3 = r1 + r2;
    cout << "r1 + r2: ";
    r3.print();

    Rational r4 = r1 - r2;
    cout << "r1 - r2: ";
    r4.print();

    Rational r5 = r1 * r2;
    cout << "r1 * r2: ";
    r5.print();

    Rational r6 = r1 / r2;
    cout << "r1 / r2: ";
    r6.print();

    return 0;
}