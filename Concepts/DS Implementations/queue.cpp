#include <bits/stdc++.h>
using namespace std;

#define MAX 100

class Node{
    public:
    int val;
    Node *next;

    Node():val(0),next(nullptr){};
    Node(int element):val(element),next(nullptr){};
    Node(int element, Node *nextPtr):val(element),next(nextPtr){};
};

class QueueUsingLinkedList;

class QueueUsingList
{
    public:
    int front;
    int rear;
    int q[MAX];
    QueueUsingList():front(-1),rear(-1){}

    void enQueue(int element){
        if(isFull()){
            cout<<"OVERFLOW"<<endl;
            return;
        }
        if(front==-1){
            q[++front] = element;
            ++rear;
            return;
        }
        rear = (rear+1)%MAX;
        q[rear]=element;
    }

    void deQueue(){
        if(front==-1){
            cout<<"UNDERFLOW"<<endl;
            return;
        }
        if(front==rear){
            front = rear = -1;
            return;
        }
        front = (front+1)%MAX;
    }
    int peek(){
        if(isEmpty()){
            cout<<"UNDERFLOW"<<endl;
            return -1;
        }
        return q[front];
    }

    void display(){
        if(isEmpty()){
            return;

        }
        for(int i=front;i<=rear;i = (i+1)%MAX){
            cout<<q[i]<<endl;
        }
    }

    bool isEmpty(){
        return (front==-1 && rear==-1);
    }
    bool isFull(){
        return (rear+1)%MAX==front;
    }
};

int main(){
    return 0;
}

class QueueUsingLinkedList
{
public:
    Node *front;
    Node *rear;

    QueueUsingLinkedList():front(nullptr),rear(nullptr){};

    void enQueue(int element)
    {
        Node *temp = new Node(element);
        if (!temp)
        {
            cout << "Overflow" << endl;
            return;
        }
        if (!front)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    int deQueue()
    {
        if (!front)
        {
            cout << "Underflow" << endl;
            return 0;
        }
        Node *temp = front;
        int x = temp->val;
        front = front->next;

        if (front == nullptr) rear = nullptr;
        delete temp;
        return x;
    }
    bool isEmpty()
    {
        return front == nullptr;
    }

    int peek()
    {
        if (!front)
        {
            cout << "Underflow" << endl;
            return 0;
        }
        return front->val;
    }
};