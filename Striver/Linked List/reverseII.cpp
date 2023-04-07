#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if(left==1){
            ListNode *rightNode = head;
            for(int i=2;i<=right;i++){
                rightNode = rightNode->next;
            }
            ListNode *rightMaintainer = rightNode->next;
            ListNode *prevPtr =nullptr;
            ListNode *nextPtr=nullptr;
            ListNode*dummyHead = head;
            while(head!=rightMaintainer){
                nextPtr = head->next;
                head->next = prevPtr;
                prevPtr = head;
                head = nextPtr;
            }
            dummyHead->next = rightMaintainer;
            return prevPtr;
        }
        ListNode *dummyHead = head;
        ListNode *leftMaintainer=nullptr;
        if (left != 1) leftMaintainer= head;
        ListNode *leftNode = head;
        ListNode *rightMaintainer;
        ListNode *rightNode = head;
        for(int i=2;i<=left;i++){
            leftNode=leftNode->next;
            if(i!=left)leftMaintainer = leftNode;
        }
        for (int i=2;i<=right;i++){
            rightNode = rightNode->next;
        }
        rightMaintainer = rightNode->next;

        leftMaintainer->next = rightNode;
        ListNode *dummyLeft = leftNode;
        ListNode *prevPtr = nullptr, *nextPtr= nullptr;
        while(dummyLeft!=rightMaintainer){
            nextPtr = dummyLeft->next;
            dummyLeft->next = prevPtr;
            prevPtr = dummyLeft;
            dummyLeft = nextPtr;
        }
        leftNode->next = rightMaintainer;
        leftMaintainer->next = rightNode;
        return head;
    }


void printLinkedList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode *insertAtEnd(ListNode *head, int content)
{
    ListNode *newHead = new ListNode(content);
    if (head == nullptr)
        return newHead;
    ListNode *dummyHead = head;
    while (head->next != nullptr)
    {
        head = head->next;
    }
    head->next = newHead;
    return dummyHead;
}

int main()
{
    ListNode *head = nullptr;
    for (int i = 1; i < 2; i++)
    {
        head = insertAtEnd(head, i);
    }
    printLinkedList(head);
    ListNode *reverseHead = reverseBetween(head,1,1);
    printLinkedList(reverseHead);
    return 0;
}
