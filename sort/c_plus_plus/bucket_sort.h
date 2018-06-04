#ifndef C_PLUS_PLUS_BUCKET_SORT_H
#define C_PLUS_PLUS_BUCKET_SORT_H

#include <iostream>
#include <iomanip>

using namespace std;

#define NBUCKET 5; // bucket size
#define INTERVAL 10; // bucket range


typedef struct node
{
    int data;
    struct node *next;
};


void bucketSort(int arr[]);
struct node *insertionSort(struct node *list);
void printBucket(struct node *list);
int getBucketIndex(int value);


/*
 * Bucket sort Average nk, Worst n^2*k, Memory nk, Stable*
 */
void bucketSort(int arr[])
{
    int i, j;
    struct node **buckets;

    /* allocate memory for array of pointers to the buckets */
    buckets = (struct node **)malloc(sizeof(struct node*) * 5);

    /* initialize pointers to the buckets */
    for(i=0; i < 5; ++i)
    {
        buckets[i] = NULL;
    }

    size_t arr_size = sizeof(arr)/sizeof(arr[0]);

    /* put items into the buckets */
    for(i=0; i<arr_size; ++i)
    {
        struct node *current;
        int pos = getBucketIndex(arr[i]);
        current = (struct node *) malloc(sizeof(struct node));
        current->data = arr[i];
        current->next = buckets[pos];
        buckets[pos] = current;
    }


    /* check what's in each bucket */
    for(i=0; i < 5; ++i)
    {
        cout << "BUCKET [" << i << "]: ";
        printBucket(buckets[i]);
        cout << endl;
    }

    /* sorting bucket using Insertion Sort */
    for(i=0; i < 5; ++i)
    {
        buckets[i] = insertionSort(buckets[i]);
    }

    /* check what's in each bucket */
    cout << "-------------" << endl;
    cout << "Bucktets after sorted" << endl;
    for(i = 0; i < 5; ++i) {
        cout << "Bucket[" << i << "] : ";
        printBucket(buckets[i]);
        cout << endl;
    }

    /* put items back to original array */
    for(j =0, i = 0; i < 5; ++i) {
        struct node *node;
        node = buckets[i];
        while(node) {
            arr[j++] = node->data;
            node = node->next;
        }
    }

    /* free memory */
    for(i = 0; i < 5; ++i) {
        struct node *node;
        node = buckets[i];
        while(node) {
            struct node *tmp;
            tmp = node;
            node = node->next;
            free(tmp);
        }
    }
    free(buckets);

}


struct node* insertionSort(struct node* list)
{
    struct node *k, *nodeList;
    if(list == 0 || list->next == 0)
    {
        return list;
    }

    nodeList = list;
    k = list->next;

    nodeList->next = 0;

    while(k!=0)
    {
        struct node *ptr;
        if(nodeList->data > k->data)
        {
            struct node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = nodeList;
            nodeList = tmp;
            continue;
        }
        for(ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
            if(ptr->next->data > k->data) break;
        }

        if(ptr->next!=0){
            struct node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        }
        else{
            ptr->next = k;
            k = k->next;
            ptr->next->next = 0;
            continue;
        }
    }
    return nodeList;
}


int getBucketIndex(int value)
{
    return value/INTERVAL;
}


void printBuckets(struct node *list)
{
    struct node *cur = list;
    while(cur) {
        cout << setw(3) << cur->data;
        cur = cur->next;
    }
}

#endif //C_PLUS_PLUS_BUCKET_SORT_H
