#include <iostream>
#include <string>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    char c;
    string s, s0;
    cout << "Введите символ C, S, S0:\n";
    cin >> c >> s >> s0; // Ввод строк
    int pos = s.find(c);
    while (pos + 1) { // Вставка строки S0 перед каждым символом C
        s.insert(pos, s0);
        pos = s.find(c, pos + s0.size() + 1);
    }
    cout << "Полученная строка:\n";
    cout << s;
}
