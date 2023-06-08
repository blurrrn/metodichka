/*
а) удалить все точки из IV четверти
б) подсчитать количество точек, лежащих на прямой y = x
в) найти все наименее удалённые от начала координат точки
г) расположить в порядке убывания координаты x,
не меняя порядок точек с одинаковой координатой x
*/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>
using namespace std;

void define_vector(vector <pair<int, int>>& points) {
    points.clear();
    int A;
    A = 2;
    points.push_back({ A / 2, -A / 2 });
    points.push_back({ -A / 2, -A / 2 });
    points.push_back({ A / 2, A / 2 });
    points.push_back({ -A / 2, A / 2 });
    A = 4;
    points.push_back({ A / 2, -A / 2 });
    points.push_back({ -A / 2, -A / 2 });
    points.push_back({ A / 2, A / 2 });
    points.push_back({ -A / 2, A / 2 });
    A = 6;
    points.push_back({ A / 2, -A / 2 });
    points.push_back({ -A / 2, -A / 2 });
    points.push_back({ A / 2, A / 2 });
    points.push_back({ -A / 2, A / 2 });
    /////////////////////////
    points.push_back({ 0, -2 });
    points.push_back({ 4, -5 });
    points.push_back({ 5, -8 });
    points.push_back({ 0, 2 });
    points.push_back({ 1, 7 });
    points.push_back({ 8, 10 });
    points.push_back({ -10, 34 });
    ////////////////////////////
    points.push_back({ 0, 1 });
    points.push_back({ 0, 2 });
    points.push_back({ 0, 3 });
    points.push_back({ -1, 2 });
    points.push_back({ 1, 2 });
    points.push_back({ 1, 5 });
    points.push_back({ 1, 1 });
    points.push_back({ 2, 4 });
    points.push_back({ 3, 2 });
    points.push_back({ 3, 1 });
    points.push_back({ 4, 4 });
    ///////////////////////////
}
void print_vector(vector <pair<int, int>>& points) {
    for (auto x : points) {
        cout << "(" << x.first << "," << x.second << ") ";
    }
    cout << endl;
}
int main() {
    vector <pair<int, int>> points;
    //a
    cout << "Solve probmlem a:\n";
    cout << "Start vector:\n";
    define_vector(points);
    print_vector(points);
    cout << "Delete all points inside IV chetvert " << endl;
    points.erase(remove_if(points.begin(), points.end(), [](pair<int, int> p) {
        return (p.first > 0 && p.second < 0);
        }), points.end());
    cout << "Result:\n";
    print_vector(points);
    //b
    cout << "Solve probmlem b:\n";
    cout << "Start vector:\n";
    define_vector(points);
    print_vector(points);
    int ans = count_if(points.begin(), points.end(), [](pair<int, int> p) {
        return p.first == p.second;
        });
    cout << "Count of points on y = x\n";
    cout << ans << endl;
    //c
    cout << "Solve probmlem c:\n";
    cout << "Start vector:\n";
    define_vector(points);
    // берем минимальный элемент из оставшихся с помощью собственного предиката
    auto it = *min_element(points.begin(), points.end(), [](pair<int, int> p1, pair<int, int> p2) {
        return sqrt(p1.first * p1.first + p1.second * p1.second) < sqrt(p2.first * p2.first + p2.second * p2.second);
        });
    cout << "Nearest (0,0) point\n";
    cout << "(" << it.first << "," << it.second << ") " << endl;
    //d
    cout << "Solve probmlem d:\n";
    cout << "Start vector:\n";
    define_vector(points);
    stable_sort(points.begin(), points.end(), [](pair<int, int> p1, pair<int, int> p2) {
        return p1.first > p2.first;
        });
    cout << "Sorted vector:\n";
    print_vector(points);
    system("pause");
}