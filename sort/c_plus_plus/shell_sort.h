#ifndef C_PLUS_PLUS_SHELL_SORT_H
#define C_PLUS_PLUS_SHELL_SORT_H

#include <iostream>
#include <iomanip>

using namespace std;

void shellSortPrint(int a[], int sz, int step)
{
    for(int i=0; i<sz; ++i)
    {
        if(((i+1)%step)!= 0){
            cout << setw(3) << a[i];
        } else {
            cout << setw(3) << a[i] << endl;
        }
    }
}


/*
 * Selection sort Average -, Worst nlogn, Memory 1, Unstable
 *Although this method is inefficient for large data sets, it is one of the fastest algorithms for sorting small numbers of elements (sets with less than 1000 or so elements). Another advantage of this algorithm is that it requires relatively small amounts of memory.
 * */
void shellSort(int a[], int sz)
{
    int i, j;
    int step, temp;

    step = sz / 2;

    while(step){
        shellSortPrint(a, sz, step);
        cout << "===>" << endl;

        for(i=step; i<sz; i++)
        {
            temp = a[i];
            j = i;
            while(j >= step && a[j-step] > temp){
                a[j] = a[j-step];
                j = j - step;
            }
            a[j] = temp;
        }
        shellSortPrint(a, sz, step);
        cout << "current array" << endl;
        shellSortPrint(a, sz, step);
        cout << "----------------" << endl;
        step = step / 2.2;
    }
}
#endif //C_PLUS_PLUS_SHELL_SORT_H
