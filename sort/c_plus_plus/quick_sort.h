#ifndef C_PLUS_PLUS_QUICK_SORT_H
#define C_PLUS_PLUS_QUICK_SORT_H

#include <iostream>
#include <iomanip>

void swapI(int a[], int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void printI(int arr[], int sz)
{
    for(int i=0; i < sz; i++)
        cout << setw(3) << arr[i];
    cout << endl;
}


/*
 * Quick sort Average nlogn, Worst n^2, Memory logn, Depends
 * */

void quickSort(int a[], int left_index, int right_index)
{
    if(left_index >= right_index) return;

    size_t sz = (int)(sizeof(a)/ sizeof(a[0]));

    int left = left_index;
    int right = right_index;
    int pivot = a[(left_index + right_index) / 2];

    while(left <= right)
    {
        while(a[left] < pivot) {
            left++;
        }

        while(a[right] > pivot){
            right--;
        }

        if(left <= right)
        {
            swapI(a, left, right);
            left++;
            right--;
        }
        printI(a, sz);
    }

    quickSort(a, left_index, right);
    quickSort(a, left, right_index);
}

#endif //C_PLUS_PLUS_QUICK_SORT_H
