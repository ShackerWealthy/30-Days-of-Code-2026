#include <iostream>
#include <algorithm>

using namespace std;

void sort_arr(int arr[], int size);

int main() {
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    
    sort_arr(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i : arr)
        cout << i << endl;

    return 0;
}

void sort_arr(int arr[], int size)
{
    int zeroes = count(arr, arr + size, 0);
    int ones   = count(arr, arr + size, 1);
    int twos   = count(arr, arr + size, 2);
    
    int i;
    
    for (i = 0; i < zeroes; ++i)
        arr[i] = 0;
        
    ones = i + ones; // Index of last 1
        
    for (; i < ones; ++i)
        arr[i] = 1;
        
    twos = i + twos; // Index of last 2
        
    for (; i < twos; ++i)
        arr[i] = 2;
}
