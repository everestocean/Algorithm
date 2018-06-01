#include "bubble_sort.h"
#include "select_sort.h"
#include "insert_sort.h"


int main() {

    cout << "############ Bubble Sort ############" << endl;
    int k;
    int a[] = {5,7,1,3,4,9,2,6,8,0};
    int b[] = {5,7,1,3,4,9,2,6,8,0};
    const size_t sz = sizeof(a)/sizeof(a[0]);
    for(k = 0; k < sz; k++)
        cout << a[k] <<" ";
    cout << endl;
    cout << "======================" << endl;
    BubbleSort(a,sz);
    cout << "======================" << endl;
    for(k = 0; k < sz; k++)
        cout << a[k] <<" ";
    cout << endl;
    cout << "======================" << endl;
    BubbleSort1(b,sz);

    cout << "############ Selection Sort ############" << endl;
    int c[] = {5,7,1,3,4,9,2,6,8,0};
    const size_t size = sizeof(c)/sizeof(c[0]);
    print(c,size);
    cout << "---------------------\n" ;
    selectionSort(c, sz);


    cout << "############ Insertion Sort ############";
    int d[] = { 15, 9, 8, 1, 4, 11, 7, 12, 13, 6, 5, 3, 16, 2, 10, 14};
    int size_d = sizeof(d)/sizeof(d[0]);

    print(d, size_d);
    cout << "---------------------\n";

    insertSort(d, size_d);

    cout << endl;
    return 0;
}