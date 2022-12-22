#include <iostream>
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
long double fact(int N){
    if (N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}
double S(double x, li k) {
    double summa = 0;
    for (li n = 1; n <= k; n++) {
        summa += ((st(-1, n+1) * st(x, 2*n-1))/fact(2*n-1));
    }
    return summa;
}
int main() {
    setlocale(LC_ALL, "Russian");
    li k;
    double x;
    cout << "Введите k, x\n";
    cin >> k >> x;
    cout << S(x, k);
}