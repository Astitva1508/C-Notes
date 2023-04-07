#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node * left;
        Node * right;
    Node(int value):val(value),left(nullptr),right(nullptr){

    }
};

int main(){
    Node * root = new Node(3);
    root->left = new Node(4);
    root->right = new Node(5);
    return 0;
}

