#include "bubble_sort.h"
#include "select_sort.h"
#include "insert_sort.h"
#include "shell_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "quick_sort.h"


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

    cout << "############ Shell Sort ############";
    int e[] = {13, 14, 94, 33, 82, 25, 59, 94, 65, 23, 45, 27, 73, 25, 39, 10};
    const size_t size_e = sizeof(e)/sizeof(e[0]);

    cout << "Initial array" << endl;
    shellSortPrint(e,size_e, size_e);
    cout << "-------------" << endl;

    shellSort(e, size_e);

    cout << "Sorted array"  << endl;
    shellSortPrint(e,size_e,size_e);


    cout << "############ Merge Sort ############" << endl;
    vector<int> v;
    v.push_back(38);
    v.push_back(27);
    v.push_back(43);
    v.push_back(3);
    v.push_back(9);
    v.push_back(82);
    v.push_back(10);

    printVector(v);
    cout << "-----------------" << endl;

    v = mergeSort(v);
    printVector(v);

    cout << "############ heap Sort ############" << endl;
    int i;
    int f[] = {19, 17, 16, 12, 9, 15, 1, 2, 11, 7, 3, 10, 14};
    const size_t size_f = sizeof(f)/sizeof(f[0]);
    for (i = 0; i < size_f; i++)
        cout << f[i] << " ";
    cout << endl;
    cout << "----------------------------------" << endl;

    heapSort(f, size_f);

    for (i = 0; i < size_f; i++)
        cout << f[i] << " ";
    cout << endl;

    cout << "############ Quick Sort ############" << endl;
    int g[] = {1, 12, 5, 26, 7, 14, 3, 7, 2};
    size_t size_g = sizeof(g)/sizeof(g[0]);
    printI(g, size_g);

    quickSort(g, 0, size_g - 1);
    cout << "----------------------------------" << endl;
    printI(g, size_g);
    return 0;
}
