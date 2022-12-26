#include <iostream>
using namespace std;

int main()
{
    int n, m;
    setlocale(LC_ALL, "Russian");
    cout << "Введите число строк: ";
    cin >> n;
    cout << "Введите число эл-тов в каждой строке: ";
    cin >> m;
    double** arr = new double* [n]; // Объявляем двумерный массив
    for (int k = 0; k < n; k++)
        arr[k] = new double[m];
    cout << "Заполняем строки элементами:\n";
    int i, j;
    for (i = 0; i < n; ++i)
    {
        cout << "Строка " << i + 1 << endl;
        for (j = 0; j < m; ++j)
            cin >> arr[i][j]; // Заполнение массива
    }
    cout << "Исходный массив:\n";
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
            cout << arr[i][j] << " "; // Вывод массива
        cout << endl;
    }
    cout << "Введите интервал значенений: ";
    double a, b;
    cin >> a >> b; // Вводим два значения
    if (b < a) // Определяем большее из них
        swap(b, a);
    double* arrSum = new double[n]; // Массив для сумм
    double summ;
    for (i = 0; i < n; ++i)
    {
        summ = 0; // Обнуляем счетчик суммы при переходе на след. строку
        for (j = 0; j < m; ++j)
        {
            if (arr[i][j]<a || arr[i][j]>b)
                summ = summ + arr[i][j];
            if (j == m - 1) // Доходим до последнего эл-та в строке 
            {
                cout << "Сумма в " << i + 1 << " строке: " << summ << endl;
                arrSum[i] = summ;
            }
        }
    }
    cout << "Массив сумм строк, не попадающих в интервал " << a << "-" << b << ":\n";
    for (i = 0; i < n; i++)
        cout << arrSum[i] << " ";
    cout << endl;
}
