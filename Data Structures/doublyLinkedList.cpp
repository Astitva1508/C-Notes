#include <iostream>
using namespace std;

class Node{
    public:
    int Value;
    Node* Previous;
    Node* Next;
};

void insertAtTheFront(Node **head,int value){
    Node *newNode = new Node();
    newNode->Value=value;
    newNode->Previous=NULL;
    newNode->Next=*head;

    (*head)->Previous=newNode;
    *head = newNode;
}

void printLinkedList(Node* head){
    while(head!=NULL){
        cout<<head->Value<<endl;
        head=head->Next;
    }
}

void insertAtTheEnd(Node **tail,int value){
    Node *newNode = new Node();
    newNode->Value=value;
    newNode->Next=NULL;
    newNode->Previous=*tail;
    (*tail)->Next = newNode;
    *tail = newNode;
}

void insertAfter(Node *prevNode,int value){
    if (prevNode==NULL) return;
    Node *newNode = new Node();
    newNode->Value = value;
    newNode->Previous=prevNode;
    newNode->Next = prevNode->Next;
    prevNode->Next=newNode;
}

void insertBefore(Node *nextNode,int value){
    if (nextNode == NULL) return;
    Node *newNode = new Node();
    newNode->Value = value;
    newNode->Previous = nextNode->Previous;
    newNode->Next = nextNode;
    nextNode->Previous = newNode;
}


int main(){

    Node* head;
    Node* tail;
    Node *node = new Node(); //Reason we use pointers to create nodes (or doubly linked lists) because linked lists are implemented with pointess because we are dynamically changing the size and elements of the list

    node->Value=1;
    node->Previous = NULL;
    node->Next=NULL;
    head = node;
    tail=node;

    node = new Node();

    node->Value = 2;
    node->Previous = tail;
    node->Next = nullptr;
    tail->Next = node;
    tail = node;

    node = new Node();

    node->Value = 3;
    node->Previous = tail;
    node->Next = nullptr;
    tail->Next = node;
    tail = node;



    insertAtTheFront(&head,0);
    insertAtTheEnd(&tail,4);//Need to check whether we should pass tail or not
    insertAtTheFront(&head,-1);
    // insertAtTheEnd(&tail,21);
    printLinkedList(head);

    return 0;
}

// Advantages over Singly Linked List
    // Can be traversed in two directions
    // Can add a given node at four places(before a given node,after a given node, at the beginning and at the end)  =>We can add and delete new nodes in double linked list faster
// Disadvantages over Singly Linked List
    // More space
    // While operating , take care of both the next and the previous nodes

// Preferred when we dont have much memory limits and when we need to perform a lot of inserting , deleting and searching etc
