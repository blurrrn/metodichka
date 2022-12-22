#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, m=100000;
    cout << "Введите количество элементов массива:\n";
    cin >> n;
    int* a = new int[n];
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Исходный массив:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    for (int i = 0; i < n; i++) {
        if (a[i] < m) m = a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == m) a[i]*=-1;
    }

    cout << endl << "Конечный массив:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}