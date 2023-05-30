#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    //считываем число n и создаем множество negative_digits
    set<int> negative_digits;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        //проходим циклом по всем n числам и, если число отрицательно, добавляем все его цифры в negative_digits
        if (x < 0) {
            while (x != 0) {
                int digit = abs(x % 10);
                negative_digits.insert(digit);
                x /= 10;
            }
        }
    }
    //проверяем, пусто ли множество negative_digits, и выводим его элементы, если они есть
    if (negative_digits.empty()) {
        cout << "No negative digits found\n";
    }
    else {
        cout << "Negative digits: ";
        for (auto digit : negative_digits) {
            cout << digit << " ";
        }
        cout << "\n";
    }

    return 0;
}
