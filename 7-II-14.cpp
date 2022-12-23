#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string s, s0, res; int l;
    char c;
    cout << "Введите строки S, S0 и символ С:\n";
    cin >> s >> s0 >> c;
    string::size_type len = s.size();
    l = s.size();
    for (int i = 0; i < l ; i++) {
        res += s[i];
        if (s[i] == c) {
            res+=s0;
        }
    }
    cout << res;
}

