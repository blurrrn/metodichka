#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a[5];
	cout << "Введите элементы одномерного массива:\n";
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	cout << "Номера нечётных элементов:\n";
	for (int i = 0; i < 10; i++) {
		if (a[i] % 2 != 0) {
			cout << i+1 << " ";
		}
	}
	cout << endl;
	int b[2][3];
	cout << "Введите элементы двумерного массива:\n";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> b[i][j];
		}
	}cout << "Итоговый массив:\n";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Номера нечётных элементов:\n";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (b[i][j] % 2 != 0) {
				cout << i + 1 << "," << j + 1 << " ";
			}
		}
	}
}
