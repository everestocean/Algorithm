#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#include <iostream>
#include <string>

using namespace std;


template <class T>
class Queue{
private:
    typedef struct Node {
        Node *next;
        T data;
    }NODE;

    NODE *head;
public:
    Queue();
    ~Queue();
    void push(T d);
    T pop();
    void print();
};


template <class T>
Queue<T>::Queue() {
    head = NULL;
}


template <class T>
Queue<T>::~Queue() {

    if (head==NULL) return;

    NODE *cur = new NODE;
    cur = head;

    while(cur){
        NODE *ptr = cur;
        cur = cur->next;
        delete ptr;
    }
}


template <class T>
void Queue<T>::push(T d) {
    if (head == NULL){
        head = new NODE;
        head->data = d;
        head->next = NULL;
        return;
    }
    NODE *cur = head;
    while(cur){
        if (cur->next == NULL){
            NODE *ptr = new NODE;
            ptr->data = d;
            ptr->next = NULL;
            cur->next = ptr;
            return;
        }
        cur = cur->next;
    }
}


template <class T>
void Queue<T>::print() {
    if (head == NULL) return;
    NODE *cur = head;
    while(cur){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}


template <class T>
T Queue<T>::pop() {
    if(head == NULL){
        cout << "empty queue" << endl;
        return NULL;
    }
    NODE *tmp = head;
    T val = head->data;

    if(head->next){
        head = head->next;
    } else {
        head = NULL;
    }
    delete tmp;
    cout << "Pop value: " << val << endl;
    return val;
}

#endif //DATA_STRUCTURE_QUEUE_H
