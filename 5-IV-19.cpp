#include <iostream>
#include <cmath>
#include <iomanip>
//double eps = 1e-10;
using namespace std;

double fun(double x, double e, int& n) {
    double s = 0, i = 1, a = (x - 1) / i;
    n = 0;
    while (fabs(a) >= e) {
        s += a;
        i++;
        a *= -1*(x-1);
        n++;
    }
    return s;
}

int main() {
    cout << fixed << setprecision(2);
    double a = 0.5, b = 1.6, h = 0.1, e, x, f;
    int n, i;
    cout << "Enter e:\n";
    cin >> e;
    cout << "# |   x  |  F(x)  | n \n";
    for (x = a, i = 1; x <= b; x += h, i++) {
        f = fun(x, e, n);
        cout << i << " | " << x << " |  " << f << " | " << n << endl;
    }
    return 0;
}