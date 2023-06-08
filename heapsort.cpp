#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
void make_heap(int* arr, int n, int i, int flag = 1) {
	int largest = i;
	int l = 2 * i + 1;
	int cnt = 2 * i + 2;
	if (flag == 1) {
		if (l < n && arr[l] > arr[largest]) largest = l;
		if (cnt < n && arr[cnt] > arr[largest]) largest = cnt;
	}
	else if (flag == 0) {
		if (l < n && arr[l] < arr[largest]) largest = l;
		if (cnt < n && arr[cnt] < arr[largest]) largest = cnt;
	}
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		make_heap(arr, n, largest);
	}
}
void pyramid_sort(int* arr, int n, int flag = 1) {
	for (int i = n / 2 - 1; i >= 0; i--) make_heap(arr, n, i, flag);
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		make_heap(arr, i, 0, flag);
	}
}
int main() {
	int n;
	setlocale(LC_ALL, "Russian");
	cout << "Enter size of array n\n";
	cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	int* temp1 = new int[n];
	int* temp2 = new int[n];
	for (int i = 0; i < n; i++) {
		int k = 2 * i;
		int y = 2 * i + 1;
		if (k >= n && y >= n) { break; }
		for (int j = 0; j < n; j++) {
			if (k < n) { temp1[j] = arr[j][k]; }
			if (y < n) { temp2[j] = arr[j][y]; }
		}
		pyramid_sort(temp1, n - 1, 0);
		pyramid_sort(temp2, n - 1);
		for (int j = 0; j < n; j++) {
			if (k < n) { arr[j][k] = temp1[j]; }
			if (y < n) { arr[j][y] = temp2[j]; }
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
		delete[]arr[i];
	system("pause");
}