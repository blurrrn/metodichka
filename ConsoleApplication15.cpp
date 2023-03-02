#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter S: ";
    cin >> s;
    int summa = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] == '0') || (s[i] == '1') || (s[i] == '2') || (s[i] == '3') || (s[i] == '4') || (s[i] == '5') ||
            (s[i] == '6') || (s[i] == '7') || (s[i] == '8') || (s[i] == '9'))
        {
            summa += int(s[i] - '0');
        }

    }
    cout << "Total: " << summa << endl;
}