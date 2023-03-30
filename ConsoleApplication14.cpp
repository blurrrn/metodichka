#include <iostream>
#include "fstream"
#include <string>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct vkladchik {
    string name, surname, secname;
    int number_of_schet, summa_deneg, year_of_begin;
    vkladchik(string name, string surname, string secname, int number_of_schet, int summa_deneg, int year_of_begin);
    void out_data();
};
vkladchik::vkladchik(string name1, string surname1, string secname1, int number_of_schet1, int summa_deneg1, int year_of_begin1) {
    name = name1;
    surname = surname1;
    secname = secname1;
    number_of_schet = number_of_schet1;
    summa_deneg = summa_deneg1;
    year_of_begin = year_of_begin1;
}
void vkladchik::out_data() {
    out << name << " " << surname << " " << secname << " " << number_of_schet << " " << summa_deneg << " " << year_of_begin << " " << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int current_year;
    cout << "Введите текущий год:" << endl;
    cin >> current_year;
    cout << "Спес<3" << endl;
    string name, surname, secname;
    int number_of_schet, summa_deneg, year_of_begin;
    string number_of_schetS, summa_denegS, year_of_beginS;
    while (in.peek() != EOF) {
        getline(in, name, ' ');
        getline(in, surname, ' ');
        getline(in, secname, ' ');
        getline(in, number_of_schetS, ' ');
        getline(in, summa_denegS, ' ');
        getline(in, year_of_beginS);
        number_of_schet = stoi(number_of_schetS);
        summa_deneg = stoi(summa_denegS);
        year_of_begin = stoi(year_of_beginS);
        vkladchik* chel = new vkladchik(name, surname, secname, number_of_schet, summa_deneg, year_of_begin);
        if (chel->year_of_begin == current_year)
            chel->out_data();
    }
    in.close();
    out.close();
}