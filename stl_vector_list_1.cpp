#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    //А) Обменять второй элемент с предпоследним.
    vector<int> vec{ 1, 2, 3, 4, 5 }; //теоретическая временная сложность O(1), т.к. операция swap выполняется за константное время

    if (vec.size() < 2) {
        cout << "vector must have at least two elements" << endl;
        return 0;
    }

    swap(vec[1], vec[vec.size() - 2]);

    for (const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;

    //Б) Удалить первый и последний элементы.
    list<int> lst{ 1, 2, 3, 4, 5 }; //теоретическая временная сложность O(1), тк операции pop_front и pop_back выполняются за константное время

    if (lst.size() < 2) {
        cout << "list must have at least two elements" << endl;
        return 0;
    }

    lst.pop_front();
    lst.pop_back();

    for (const auto& elem : lst) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
