#include "sort.h"

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

    return 0;
}