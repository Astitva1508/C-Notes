#include <bits/stdc++.h>
using namespace std;

#define MAX 100

class Node{
    public:
    int val;
    Node *next;
    Node():val(0),next(nullptr){};
    Node(int value):val(value),next(nullptr){};
    Node(int value,Node *nextPtr):val(value),next(nextPtr){};
};

class StackUsingLinkedList{
    public:
    Node *top;
    StackUsingLinkedList():top(nullptr){};

    void push(int element){
        Node *temp = new Node(element);
        if(!temp){
            cout<<"OVERFLOW"<<endl;
            return;
        }
        temp->next = top;
        top = temp;
    }
    int pop(){
        if(!top){
            cout<<"UNDERFLOW"<<endl;
            return 0;
        }
        Node *temp = top;
        int x = temp->val;
        top = top->next;
        delete temp;
        return x;
    }
    int peek(){
        if(!top){
            cout<<"UNDERFLOW"<<endl;
            return 0;
        }
        return top->val;
    }
    bool isEmpty(){
        return top==nullptr;
    }
    void traverse(){
        while(!isEmpty()){
            cout<<pop()<<endl;
        }
    }

};

int main(){
    StackUsingLinkedList* st = new StackUsingLinkedList();
    st->push(10);
    st->push(15);
    st->push(20);
    st->push(25);
    cout<<st->isEmpty()<<endl;
    cout<<st->pop()<<endl;
    cout<<st->peek()<<endl;
    st->traverse();

    return 0;
}

class StackUsingList
{
public:
    int top;
    int stack[MAX];
    StackUsingList() : top(-1){};
    void push(int element)
    {
        if (top >= MAX - 1)
        {
            cout << "OVERFLOW" << endl;
            return;
        }
        stack[++top] = element;
    }
    int pop()
    {
        if (top < 0)
        {
            cout << "UNDERFLOW" << endl;
            return 0;
        }
        return stack[top--];
    }
    int peek()
    {
        if (top < 0)
        {
            cout << "UNDERFLOW" << endl;
            return 0;
        }
        return stack[top];
    }
    bool isEmpty()
    {
        return top < 0;
    }
    void traverse()
    {
        while (top >= 0)
        {
            cout << stack[top--] << " ";
        }
    }
};
