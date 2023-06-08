/*
I (map)
 Во входном файле задан набор слов и целых чисел, разделённых пробелами.
15)   Для каждого числа найти позиции
 всех вхождений его самого и противоположного ему
*/
#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
map<int, vector<int>> numbers_counter(string s, char c = ' ') {
    string temp = "";
    map<int, vector<int>> res;
    s += c;
    int cnt = 0;
    for (int k = 0; k < s.size(); k++) {
        if (s[k] != c) {
            temp += s[k];
        }
        else {
            int coef = 1;
            if (temp[0] == '-') {
                temp.erase(temp.begin());
                coef = -1;
            }
            auto it = temp.begin();
            while (it != temp.end() && isdigit(*it)) ++it;
            if (!temp.empty() && it == temp.end()) {
                int u = (coef * stoi(temp));
                if (res.count(u) != 0) {
                    vector <int> tmp{ cnt };
                    res.insert(make_pair(u, tmp));
                }
                res[u].push_back(cnt);
            }
            temp = "";
            cnt++;
        }
    }
    return res;
}
void print_ans(map<int, vector<int>> m) {
    set <int> used;
    for (auto key1 : m) {
        //auto k = key1;
        for (auto key2 : m) {
            if (key1.first == (-1) * key2.first && key1.first != 0 && used.find(key1.first) == used.end() && used.find(key2.first) == used.end()) {
                used.insert(key1.first);
                used.insert(key2.first);
                cout << "Numbers:\n";
                cout << key1.first << " : ";
                for (auto x : key1.second) { cout << x << " "; }
                cout << endl;
                cout << key2.first << " : ";
                for (auto x : key2.second) { cout << x << " "; }
                cout << endl;
            }
        }
    }
}
int main() {
    ifstream fin;
    ofstream fout;
    fout.open("kakasmua.txt");
    fin.open("mapI_input.txt");
    string s = "", tmp;
    while (fin.peek() != EOF) {
        getline(fin, tmp);
        tmp = " " + tmp;
        s += tmp;
    }
    auto ans = numbers_counter(s);
    print_ans(ans);
    system("pause");
}