#include <iostream>

using namespace std;

void swap(int& x1, int& x2) {
    int temp;
    temp = x1;
    x1 = x2;
    x2 = temp;
}
void insert_stolb(int** arr, int idx, int m) {

}

int main() {
    setlocale(LC_ALL, "rus");
    int n, m;
    cout << "Введите размерность массива\n";
    cin >> n >> m;
    int** tab;
    tab = new int* [n * 2];
    for (int i = 0; i < n; i++)
        tab[i] = new int[m * 2];
    cout << "Введите число\n";
    //cin >> x;
    //for (int i = 0; i < n; i++)
        //for (int j = 0; j < m; j++)

    cout << "Введите массив\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> tab[i][j];

    //////////////////////////////////
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

        }
    }
    /////////////////////////////////
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << tab[i][j] << " ";
        cout << endl;
    }
}
