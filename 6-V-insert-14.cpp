#include "iostream"

using namespace std;

int main()
{
    int n, newEl, k;
    setlocale(LC_ALL, "Russian");
    cout << "Введите заданную цифру: ";
    cin >> k;
    cout << "Введите кол-во эл-тов массива: ";
    cin >> n;
    int m = n * 2;
    int* mas = new int[m]; // Ввод одномерного массива
    cout << "Введите эл-ты массива: \n";
    for (int i = 0; i < n; i++){
        cout << "mas[" << i << "] = ";
        cin >> mas[i];
    }
    cout << "Введите новый элемент: ";
    cin >> newEl;
    for (int i = n; i >= 0; i--)
    {
        int temp = 0;
        temp = mas[i];
        while (temp){
            if (temp % 10 == k){ // Проверка на нахождение цифры
                for (int j = m; j > i; j--){
                    mas[j] = mas[j - 1]; // Вставка элемента
                }
                mas[i] = newEl;
                n++;
                break;
            }
            temp /= 10;
        }
    }
    cout << "Конечный массив: \n";
    for (int i = 0; i < n; i++){ // Вывод конечного массива
        cout << "mas[" << i << "] = " << mas[i] << endl;
    }
}
