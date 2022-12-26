#include <iostream>
#include <cmath>
using namespace std;

double S(double x, int k) { // Вспомогательная функция для вычисления суммы
    double summa = 0;
    double t = 1;
    for (int n = 1; n <= k; n++) {
        t = t*(2 * n - 1); // Факториал
        summa += ((pow(-1, n + 1) * pow(x, 2 * n - 1)) / t);
    }
    return summa;
}
int main() {
    setlocale(LC_ALL, "Russian");
    int k;
    double x;
    cout << "Введите k, x\n";
    cin >> k >> x;
    cout << S(x, k); // Вызов функции
}
