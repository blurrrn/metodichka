#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n; double sum = 0, k = 0;
    cout << "Введите размер квадратной матрицы:\n";
    cin >> n;
    double **b = new double* [n];
    for (int i = 0; i < n; i++) {
        b[i] = new double[n];
    }
    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    cout << "Исходная матрица:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j > n - 1) {
                sum += b[i][j];
                k++;
            }
        }
    }
    cout << "Среднее арифметическое:" << sum/k;
}