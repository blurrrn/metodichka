#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, t;
	getline(cin, s);
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if ((int)s[i] >= (int)'0' && (int)s[i] <= (int)'9') {
			sum += (int)s[i] - 48;
		}
	}
	cout << sum;
}
