#include <iostream>
#include <vector>

using namespace std;

void merge_func(vector<int>& arr, int begin, int mid, int end)
{
                         
    int n1 = mid - begin + 1;
    int n2 = end - mid;

    vector<int> begin_arr(n1), end_arr(n2);

    for (int i = 0; i < n1; i++)
        begin_arr[i] = arr[begin + i];
    for (int j = 0; j < n2; j++)
        end_arr[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = begin;

    while (i < n1 && j < n2) {
        if (begin_arr[i] <= end_arr[j]) {
            arr[k] = begin_arr[i];
            i++;
        }
        else {
            arr[k] = end_arr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = begin_arr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = end_arr[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& arr, int begin, int end)
{
    
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    merge_sort(arr, begin, mid);
    merge_sort(arr, mid + 1, end);
    merge_func(arr, begin, mid, end);
}

int main()
{
    vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = arr.size();

    merge_sort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
    
    return 0;
}
