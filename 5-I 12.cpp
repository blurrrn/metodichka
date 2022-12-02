#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    double x, s=0;
    cout << "n=\n";
    cin >> n;
    cout << "x=\n";
    cin >> x;
    for (int i = 1; i <= n; i++) {
        s += sin(pow(x, i));
    }
    cout << "s=" << s;
}