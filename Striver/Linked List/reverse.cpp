#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int value;
    ListNode *next;
    ListNode():value(0),next(nullptr){};
    ListNode(int content):value(content),next(nullptr){};
    ListNode(int content , ListNode *Next):value(content),next(Next){};
};

// Iterative Approach
// ListNode* reverse(ListNode* head){
//     ListNode *prev = nullptr;
//     ListNode *next = nullptr;
//     while (head!=nullptr){
//         next = head->next;
//         head->next = prev;
//         prev = head;
//         head = next;
//     }
//     return prev;
// }

// Recursive Approach

ListNode *reverseRecursive(ListNode *head,ListNode *prevNode)
{
    if (head==nullptr) return prevNode;
    ListNode *cache = head->next;
    head->next = prevNode;
    return reverseRecursive(cache,head);
}

void printLinkedList(ListNode *head){
    while(head!=nullptr){
        cout<<head->value<<" ";
        head=head->next;
    }
    cout<<endl;
}

ListNode* insertAtEnd(ListNode* head,int content){
    ListNode *newHead = new ListNode(content);
    if (head == nullptr) return newHead;
    ListNode *dummyHead = head;
    while(head->next!=nullptr){
        head= head->next;
    }
    head->next = newHead;
    return dummyHead;
}

int main(){
    ListNode* head=nullptr;
    for(int i=1;i<6;i++){
        head = insertAtEnd(head,i);
    }
    printLinkedList(head);
    ListNode *reverseHead = reverseRecursive(head,nullptr);
    printLinkedList(reverseHead);
    return 0;
}