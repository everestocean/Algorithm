#ifndef C_PLUS_PLUS_SORT_H
#define C_PLUS_PLUS_SORT_H

#include <iostream>

using namespace std;


/* Bubble sort Average n^2, Worst n^2, Memory 1, Stable*
 * comparing each pair of adjacent items and swapping them if they are in the wrong order.
*/
void BubbleSort(int *a, int size)
{
    int i, j, temp;
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-1; j++)
        {
            if(*(a+j) > *(a+j+1)){
                temp = *(a+j+1);
                *(a+j+1) = *(a+j);
                *(a+j) = temp;
            }
        }
        for(int k=0; k<size; k++)
        {
            cout << *(a+k) << " ";
        }
        cout << endl;
    }
}


void BubbleSort1(int a[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for(j=0; j<size-1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }

        for(int k=0; k<size; k++)
        {
            cout << a[k] << " ";
        }
        cout << endl;
    }

}


#endif //C_PLUS_PLUS_SORT_H
