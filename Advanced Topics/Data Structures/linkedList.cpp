#include <iostream>
using namespace std;

class Node{
    public:
    int Value;
    Node *Next;
};
void insertAtTheFrontMyWay(Node **headAddress, int value);
void printLinkedList(Node *node);
void insertAtTheEnd(Node **head, int value);
void insertAfter(Node *prevNode,int value){
    //Steps to Insert a Node after a specific Node
    // Check if previous node is null
    if (prevNode == NULL)
        return;
    // Prepare a newNode
    Node *newNode = new Node();
    newNode->Value = value;
    newNode->Next = prevNode->Next;
    // Insert newNode after previous
    prevNode->Next = newNode;
}
int main(){
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    head->Value=1;
    head->Next=second;
    second->Value = 2;
    second->Next = third;
    third->Value = 3;
    third->Next = NULL;

    // insertAtTheFront(&head,0);
    // The reason we pass the address of the head , because we defo will change what we will be storing at the head
    // insertAtTheEnd(&head,4);
    // insertAtTheEndError(&head,5);
    insertAfter(second,100);
    printLinkedList(head);
    return 0;
}

//A linked list stores data is a non-continous memory
//To access the elements of an array, we only need the address of the first element
//However, to access the elements of a linked list, we need to link the elements
//Each element stores the value and the address of the next element
//The first element is called the HEAD Element

// Advantages of Linked Lists Over Arrays 
// Dynamic Size

// Disadvantages
// Random access to the elements of the linked list is not allowed
// Need more memory

void printLinkedList(Node *node)
{
    while (node != NULL)
    {
        cout << node->Value << endl;
        node = node->Next;
    }
}

void insertAtTheFrontMyWay(Node **headAddress, int value)
{
    // headAddress = &head
    //*headAdress = head
    Node *x = new Node();
    *x = **headAddress;
    // At the address of x , we store what was stored in the address at head Node.
    (*headAddress)->Value = value;
    (*headAddress)->Next = x;
}

void insertAtTheFront(Node **headAddress, int value)
{
    // Steps to insert at the front of a Linked List
    // Prepare a new Node
    // Put it in front of current head
    // Move head of the list to point to the newNode
    Node *newNode = new Node();
    newNode->Value = value;
    newNode->Next = *headAddress;
    *headAddress = newNode;
}

void insertAtTheEndMyWay(Node *node, int value)
{
    while (node->Next != NULL)
    {
        node = node->Next;
    }
    Node *newNode = new Node();
    node->Next = newNode;
    newNode->Next = NULL;
    newNode->Value = value;
}

void insertAtTheEnd(Node **head, int value)
{
    // head = head Node ka address ka address
    //*head  = head Node ka address

    // Steps to insert at the end of a linked List
    // Prepare a new Node
    Node *newNode = new Node();
    newNode->Value = value;
    newNode->Next = NULL;
    // If Linked List is empty , new Node will be the head node
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    // Find the last node
    Node *last = *head;
    while (last->Next != NULL)
    {
        last = last->Next;
    }
    // Insert new node after the last node (at the end)
    last->Next = newNode;
}

void insertAtTheEndError(Node **head, int value)
{
    Node *newNode = new Node();
    newNode->Value = value;
    newNode->Next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while ((*head)->Next != NULL)
    {
        *head = (*head)->Next;
    }
    (*head)->Next = newNode;
}

