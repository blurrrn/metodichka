#include <iostream>
#include <cmath>

using namespace std;
typedef long long li;

double st(double x, li n) {
    double res = 1;
    while (n) {
        if (n & 1) {
            res *= x;
            --n;
        }
        else {
            x *= x;
            n >>= 1;
        }
    }
    return res;
}
double f(li i) {
    return 1. / (st(5,i) + st(4,i+1));
}
int main() {
    setlocale(LC_ALL, "Russian");
    double e, s = 0, curr;
    cout << "Введите e\n";
    cin >> e;
    curr = e + 1;
    int i = 1;
    while (fabs(curr) > e) {
        curr = f(i);
        s += curr;
        i++;
    }
    cout << s;
}