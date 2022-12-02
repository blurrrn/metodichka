
#include <iostream>
#include <cmath>
using namespace std;

double f(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    else
        return (n * f(n - 2) - f(n - 1)) / (n + 1);
}

int main()
{
    int x;
    cin >> x;
    for (int i = 1; i <= x; i++) {
        cout << f(i) << endl;
    }
}
