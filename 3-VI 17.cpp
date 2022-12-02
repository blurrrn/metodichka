#include <iostream>
#include <cmath>
using namespace std;

int f(int a, int b, int x) {
    if (x < 93) {
        return a + b * x;
    }
    else if (x >= 93 && x <= 120) {
        return b - a * x;
    }
    else {
        return a * b * x;
    }
}

int main()
{
    int a, b, h;
    cin >> a >> b >> h;
    cout << a << "\n";
    for (int x = a; x <= b; x += h)
    {
        cout << "x=" << x << " " << "y=" << f(a, b, x) << "\n";
    }
}