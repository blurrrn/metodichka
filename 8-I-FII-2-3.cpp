#include <iostream>
using namespace std;

int F(int n) { // Вспомогательная функция для подсчёта кол-ва делителей
	int k = 0;
	if (n > 0) {
		for (int i = 1; i <= n; i++) {
			if (n % i == 0) k++;
		}
		return k;
	}
	else {
		for (int i = -1; i >= n; i--) {
			if (n % i == 0) k++;
		}
		return k;
	}
}

int main()
{
	int a, b, m = -1;
	cout << "Enter [a,b]:\n";
	cin >> a >> b;
	for (int i = a; i <= b; i++) { // Нахождение максимального кол-ва делителей
		if (F(i) > m) m = F(i);
	}
	for (int i = a; i <= b; i++) { // Вывод чисел с макс. значениями
		if (F(i)==m) cout << i << " ";
	}
}
