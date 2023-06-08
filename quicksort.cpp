#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int findpivot(int* a, int left, int right) //поиск индекса опорного элемента на участке массива от i до j, ищется наибольший из первых двух различных
{
    int firstkey = a[left];
    for (int k = left + 1; k <= right; k++)
        if (a[k] > firstkey) {
            return k;
        }
        else if (a[k] < firstkey)
        {
            return left;
        }
    return -1;
}

int partition(int* a, int i, int j, int pivot, bool flag) //перераспределение элементов массива на участке от i до j относительно pivot, pivot - опорный элемент
                                                          //элементы перераспределяются таким образом, что сначала идут все меньшие опорного, потом - большие.
{
    int l = i, r = j;
    if (flag == false) {
        do
        {
            while (a[l] < pivot)
                l++;
            while (a[r] >= pivot)
                r--;
            if (l < r)
                swap(a[r], a[l]);
        } while (l <= r);
        return l;
    }
    else {
        do
        {
            while (a[l] >= pivot)
                l++;
            while (a[r] < pivot)
                r--;
            if (l < r)
                swap(a[r], a[l]);
        } while (l <= r);
        return l;
    } //метод возвращает индекс точки разбиения
}
void quicksort(int* a, int start, int end, bool flag = false)
{
    int pivotindex = findpivot(a, start, end); //ищется индекс опорного элемента
    if (pivotindex != -1) {
        int pivot = a[pivotindex]; //опорный элемент
        int k = partition(a, start, end, pivot, flag); //k - это номер первого элемента в перераспределенном массиве, который больше или равен опорному.
                                                       //То есть от k до end все элементы будут больше или равны опорному после выполнения данной функции. Соответственно от start до k-1 - меньше
        if (end <= start)
            return;
        quicksort(a, start, k - 1, flag); //рекурсивно применяем к каждой части массива
        quicksort(a, k, end, flag);
    }
    return;
}

int main()
{
    int n;
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
        quicksort(temp1, 0, n - 1, true);
        quicksort(temp2, 0, n - 1);
        for (int j = 0; j < n; j++) {
            if (k < n) { arr[j][k] = temp1[j]; }
            if (y < n) { arr[j][y] = temp2[j]; }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    system("pause");
}