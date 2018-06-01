#ifndef C_PLUS_PLUS_INSERT_SORT_H
#define C_PLUS_PLUS_INSERT_SORT_H

#include <iostream>
#include <iomanip>

using namespace std;


void swap(int &x, int &y)
{
    int tmp;
    tmp = x;
    x= y;
    y = tmp;
}

/*
 * Insertion sort Average n^2, Worst n^2, Memory 1, Stable*
 */
void insertSort(int a[], int sz)
{
    for(int i=0; i < sz; i++)
    {
        int j = i;
        while(j > 0 && (a[j] < a[j-1]))
        {
            swap(a[j], a[j-1]);
            j--;
        }
        for(int k = 0; k<sz; k++) cout << a[k] << " ";
        cout << endl;
    }
}

#endif //C_PLUS_PLUS_INSERT_SORT_H
