#include "linked_list.h"
#include "linked_list_template.h"
#include "stack.h"
#include "queue.h"
#include "binary_tree.h"


int main() {

    struct Node* newHead;
    struct Node* head = new Node;

    initNode(head, 10);
    display(head);

    addNode(head, 30);
    display(head);

    addNode(head, 35);
    display(head);

    addNode(head, 40);
    display(head);

    insertFront(&head, 5);
    display(head);

    int numDel = 5;
    Node *ptrDelete = searchNode(head, numDel);
    if(deleteNode(&head, ptrDelete))
        cout << "Node " << numDel << " delete" << endl;
    display(head);

    cout << "The list is reversed!" << endl;
    reverse(&head);
    display(head);

    cout << "The list is copy!" << endl;
    copyLinkedList(head, &newHead);
    display(newHead);

    cout << "Comparing the two list.... \n";
    cout << "Are the two lists is the same?\n";

    if(compareLinkedList(head, newHead))
        cout << "Yes, they are the same!\n";
    else
        cout << "No, they are not the same!\n";
    cout << endl;

    numDel = 35;
    ptrDelete = searchNode(newHead, numDel);
    if(deleteNode(&newHead, ptrDelete))
    {
        cout << "Node " << numDel << " deleted" << endl;
        cout << "The new list after the delete is\n";
        display(newHead);
    }
    cout << "Compare the two lists again.....\n";
    cout << "Are the two lists same?\n";
    if(compareLinkedList(head, newHead))
    {
        cout << "Yes, the two lists are same!\n";
    } else{
        cout << "No, the two lists are different!\n";
    }
    cout << endl;
    cout << "Deleting the copied list\n";
    deleteLinkedList(&newHead);
    display(newHead);


    // linked list template
    cout << "########### Linked list template #############" << endl;
    LinkedList<string> sList;
    sList.add("Wolfgang Amadeus Mozart");
    sList.add("Franz Peter Schubert");
    sList.add("Pyotr Ilyich Tchaikovsky");
    sList.add("Clude-Achille Debussy");
    sList.add("Camille Saint-Saens");
    sList.display("string");
    sList.clear();

    LinkedList<int> iList;
    iList.add(40);
    iList.add(50);
    iList.add(60);
    iList.add(70);
    iList.add(80);
    iList.add(90);
    iList.add(100);
    iList.add(10);
    iList.add(20);
    iList.add(30);
    iList.display("integer");

    /* link last element to the first */
    iList.makeCircular();

    if(iList.isCircular()) cout <<"This is circular list\n";
    iList.display("integer");

    iList.clear();
    cout << "\ndisplay after clear()\n";
    iList.display("integer");


    cout << "################### Stack Class using Linked list ##################" << endl;
    Stack<int> *st = new Stack<int>;
    st->push(10);
    st->push(20);
    st->push(30);
    st->push(40);
    st->push(50);

    st->print();

    st->pop();
    st->pop();
    st->print();

    cout << "Current top = " << st->peek() << endl;
    delete st;

    cout << "################### Queue Class using Linked list ##################" << endl;
    Queue<int> *que = new Queue<int>;
    que->push(10);
    que->push(20);
    que->push(30);
    que->push(40);
    que->push(50);
    que->print();

    que->pop();que->print();
    que->pop();que->print();
    que->pop();que->print();
    que->pop();que->print();
    que->pop();que->print();

    cout << "################### Binary Search tree ##################" << endl;
    int i, i1, i2;

    TREE *front;
    TREE *succ;
    TREE *pred;
    TREE *ancestor;

    int intArr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    TREE *root = newTreeNode(6);


    insertTreeNode(root, 2);
    insertTreeNode(root, 1);
    insertTreeNode(root, 4);
    insertTreeNode(root, 3);
    insertTreeNode(root, 5);
    insertTreeNode(root, 7);
    insertTreeNode(root, 9);
    insertTreeNode(root, 8);

    //is the tree BST
    isBST(root);

    //size of the tree
    cout << "Size = " << treeSize(root) << endl;

    //max depth
    cout << "max depth = " << maxDepth(root) << endl;

    //min depth
    cout << "min depth = " << minDepth(root) << endl;

    //balance tree?

    if(isBanlanced(root))
        cout << "This tree is balance!\n";
    else
        cout << "This tree is not balance!\n";

    //min value of the tree
    if(root)
        cout << "Min value = " << minTree(root)->data << endl;

    //max value of the tree
    if(root)
        cout << "Max value = " << maxTree(root)->data << endl;

    /* get the level of a data: root level = 0 */
    cout << "Node 2 is at level: " << getLevel(root, 2, 0) << endl;
    cout << "Node 7 is at level: " << getLevel(root, 7, 0) << endl;
    cout << "Node 6 is at level: " << getLevel(root, 6, 0) << endl;

    /* separate even/odd level elements */
    level_even_odd(root);

    return 0;
}