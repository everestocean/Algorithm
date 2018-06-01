#ifndef C_PLUS_PLUS_SELECT_SORT_H
#define C_PLUS_PLUS_SELECT_SORT_H

#include <iostream>

using namespace std;

void swap(int *n, int *m)
{
    int tmp;
    tmp = *m;
    *m = *n;
    *n = tmp;
}


void print(int a[], int sz)
{
    for(int i = 0; i<sz; i++) cout << a[i] << " ";
    cout << endl;
}


/*
 * Selection sort Average n^2, Worst n^2, Memory 1, Unstable
 * */

void selectionSort(int a[], int sz)
{
    int i,j,mn;

    for(int i=0; i<sz; i++)
    {
        mn = i;
        for(j=i+1; j<sz; j++)
        {
            if(a[j] < a[mn]) mn = j;
        }
        swap(a[mn], a[i]);
        print(a, sz);
    }
}

#endif //C_PLUS_PLUS_SELECT_SORT_H
