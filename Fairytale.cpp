
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string a, b, treasure, weapon, place;
	cout << "Введите имя героя:" << "\n";
	cin >> a;
	cout << "Введите имя злодея" << "\n";
	cin >> b;
	cout << "Место:" << "\n";
	cin >> place;
	cout << "Сокровище:" << "\n";
	cin >> treasure;
	cout << "Оружие:" << "\n";
	cin >> weapon;
	cout << "Как-то раз " << a << " решил(а) отправиться на поиски " << treasure << " в " << place << "." << "\n" << "Оказавшись там, он(а) встретил(а) огромное чудовище под названием " << b << ", которое охраняло драгоценное сокровище." << "\n" << "Недолго думая, " << a << " достал(а) свой волшебный " << weapon << " и одолел(а) своего врага." << "\n" << "После этого он(а) наконец заполучил(а) " << treasure << " и жил(а) долго и счастливо!" << "\n";

}