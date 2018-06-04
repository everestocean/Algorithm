#ifndef C_PLUS_PLUS_HEAP_SORT_H
#define C_PLUS_PLUS_HEAP_SORT_H

#include <iostream>

using namespace std;


void swap(int *m, int *n)
{
    int tmp;
    tmp = *m;
    *m = *n;
    *n = tmp;
}


void siftDown(int *a, int k, int N)
{
    while(k*2 + 1 < N)
    {
        /* For zero-based arrays, the children are 2*i+1 and 2*i+2 */
        int child = 2*k + 1;

        /* get bigger child if there are two children */
        if((child + 1) < N && (a[child] < a[child+1])) child++;

        if(a[k] < a[child])
        {
            swap(a[child], a[k]);
            k = child;
        } else {
            return;
        }
    }
}


/*
 * Merge sort Average nlogn, Worst nlogn, Memory 1, Unstable
 * */
void heapSort(int a[], int N)
{
    for(int k = N/2; k>=0; k--){
        siftDown(a, k, N);
    }

    while(N-1 > 0)
    {
        /* swap the root(maximum value) of the heap
		with the last element of the heap */
        swap(a[N-1], a[0]);

        /* put the heap back in max-heap order */
        siftDown(a, 0, N-1);

        /* N-- : decrease the size of the heap by one
		so that the previous max value will
        	stay in its proper placement */
        N--;
    }
}
#endif //C_PLUS_PLUS_HEAP_SORT_H
