#include <iostream>
#include <cmath>

using namespace std;

float F(float x) {
	if (abs(x) <= 0.1)
		return x * x * x - 0.1;
	if (abs(x) > 0.1 && abs(x) <= 0.2)
		return 0.2 * x - 0.1;
	if (abs(x) > 0.2)
		return x * x * x + 0.1;
}
void F(float x, float& y) {
	y = F(x);
}

int main()
{
	float x, y, step;
	setlocale(LC_ALL, "Russian");
	cout << "Введите шаг расчета значений\n";
	cin >> step;
	cout << "x  f(x)" << endl;
	for (x = -1.; x <= 13.; x += step) {
		cout << x << "  " << F(x) << endl;
	}
	cout << "------------\n";
	cout << "x  f(x)" << endl;
	for (x = -1.; x <= 13.; x += step) {
		F(x, y);
		cout << x << "  " << y << endl;
	}
}
