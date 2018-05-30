#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Stack {
private:
    typedef struct node {
        node *next;
        T data;
    }NODE;

    NODE *top;
public:
    Stack();
    ~Stack();
    void push(T d);
    T pop();
    T peek();
    void print();
};

template <class T>
Stack<T>::Stack() {
    top = NULL;
}

template <class T>
Stack<T>::~Stack() {
    while(top){
        NODE *tmp = top;
        top = top->next;
        delete tmp;
    }
}


template <class T>
void Stack<T>::push(T d) {
    NODE *ptr = new NODE;
    ptr->next = top;
    ptr->data = d;
    top = ptr;
}


template <class T>
T Stack<T>::pop() {
    NODE *tmp = new NODE;
    T val = top->data;
    top = top->next;
    delete tmp;
    return val;
}


template <class T>
T Stack<T>::peek() {
    return top->data;
}


template <class T>
void Stack<T>::print() {
    Stack::NODE *cur = top;

    while(cur){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

#endif //DATA_STRUCTURE_STACK_H
