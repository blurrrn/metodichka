
#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    if (4-x*x<=0) {
        return -9999;
    }
    else {
        return log(4-x*x);
    }
}

int main()
{
    double a, b, h;
    cin >> a >> b >> h;
    cout << a << "\n";
    for (double x = a; x <= b; x += h)
    {
        cout << "x=" << x << " " << "y=" << f(x) << "\n";
    }
}