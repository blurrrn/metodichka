#include <iostream>

using namespace std;

int count_of_divisors(int n, int d) {
    if (d == abs(n))
        return 1;
    else
        if (n % d == 0)
            return 1 + count_of_divisors(abs(n), d + 1); // Модуль на случай если будут отрицательные числа
        else
            return count_of_divisors(abs(n), d + 1); // Хотя в условии они натуральные, но ладно
}

int main() {
    setlocale(LC_ALL, "Russian");
    int a, b,temp, mx = -1, ans;
    cout << "Введите отрезок a b\n";
    cin >> a >> b;
    if (a > b) {
        cout << "Такого отрезка не существует, значения поменяем местами\n";
        temp = a;
        a = b;
        b = temp;
    }
    for (int n = a; n <= b; n++) {
        temp = count_of_divisors(n, 1);
        if (temp > mx) {
            mx = temp;
            ans = n;
        }
    }
    cout << "Число с максимальным количеством делителей на отрезке [" << a << "," << b << "]\n";
    cout << "число: " << ans << "\nколичество делителей: " << mx;
}
