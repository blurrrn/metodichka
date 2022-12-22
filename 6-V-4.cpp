#include <iostream>

using namespace std;

void delet_el(int& length, int* arr, int& idx) {
    for (int i = idx; i < length; i++) {
        arr[i] = arr[i + 1];
    }
    --length;
    --idx;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n, x;
    cout << "Введите количество элементов массива:\n";
    cin >> n;
    cout << "Введите цифру, которая должна быть последней, чтобы удалить элемент:\n";
    cin >> x;
    cout << "Введите элементы массива:\n";
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        if (a[i] % 10 == x)
            delet_el(n, a, i);

    cout << "Полученный массив\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}
