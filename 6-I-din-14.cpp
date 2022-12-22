#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество элементов одномерного массива:\n";
	cin >> n;
	int *a = new int[n];
	cout << "Введите элементы одномерного массива:\n";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << "Номера нечётных элементов:\n";
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0) {
			cout << i + 1 << " ";
		}
	}
	cout << endl;
	int x, y;
	cout << "Введите количество строк и столбцов двумерного массива:\n";
	cin >> x >> y;
	int **b=new int*[x];
	for (int i = 0; i < x; i++) {
		b[i] = new int[y];
	}
	cout << "Введите элементы двумерного массива:\n";
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> b[i][j];
		}
	}cout << "Итоговый массив:\n";
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Номера нечётных элементов:\n";
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (b[i][j] % 2 != 0) {
				cout << i + 1 << "," << j + 1 << " ";
			}
		}
	}
}