#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string s, slovo;
    char c, C;
    string::size_type k = 0, pos = 0;
    string r = ",.:;!? ";
    cout << "Введите предложение S и символ С:\n";
    getline(cin, s);
    cin >> c >> C;
    k = s.find_first_of(r, pos);
    while (k!=s.npos){
        slovo = s.substr(pos, k - pos);
        while (ispunct(s[k]))k++;
        pos = k + 1;
        if (slovo[0] == c || slovo[0] == C) cout << slovo << endl;
        k = s.find_first_of(r, pos);
    }
}
