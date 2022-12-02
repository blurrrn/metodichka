#include <iostream>
using namespace std;

int main()
{
    int a, n;
    a = 8;
    n = 1;
    while (a > 4) {

        for (int i = 1; i <= n; i++) {
            cout << a << " ";
        }
        cout << "\n";
        a -= 1;
        for (int i = 1; i <= n; i++) {
            cout << a << " ";
        }
        n += 1;
        cout << "\n";
    }
}