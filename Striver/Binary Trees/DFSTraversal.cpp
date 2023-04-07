#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *left;
    Node *right;
    Node(int value) : val(value), left(nullptr), right(nullptr){}
};

void preOrderTraversal(Node *);
void preOrderTraversalIterativeMyWay(Node *);
void preOrderTraversalIterative(Node *);
void inOrderTraversal(Node *);
void inOrderTraversalIterative(Node *);

int main(){
    Node *root = new Node(3);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(10);
    root->right->left = new Node(2);
    root->right->right= new Node(12);
    root->left->right = new Node(15);
    root->left->right->right = new Node(9);

    stack<Node *> st;
    st.push(root);

    Node *dummy;
    while (!st.empty())
    {
        dummy = st.top();
        if (dummy->left != nullptr)
        {
            st.push(dummy->right);
        }
        else if(dummy->right!=nullptr){
            st.push(dummy->left);
        }
        else{
            st.pop();
        }
            
    }
    cout << endl;

    return 0;
}

void inOrderTraversalIterative(Node * root){
    stack<Node*> st;
    st.push(root);

    Node * dummy;
    while(!st.empty()){
        dummy = st.top();
        if (dummy->left!=nullptr){
            st.push(dummy->left);
        }
        else{
            cout<<dummy->val<<" ";
            st.pop();
            if(dummy->right!=nullptr) st.push(dummy->right);
            else if(!st.empty()){
                dummy = st.top();
                cout<<dummy->val<<" ";
                st.pop();
                if(dummy->right!=nullptr) st.push(dummy->right);
            }
        }
    }
    cout<<endl;
}

void preOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void preOrderTraversalIterativeMyWay(Node *root)
{
    stack<Node *> st;
    st.push(root);

    Node *dummy;
    while (!st.empty())
    {
        dummy = st.top();
        cout << dummy->val << " ";
        st.pop();
        if (dummy->right != nullptr)
            st.push(dummy->right);
        if (dummy->left != nullptr)
            st.push(dummy->left);
    }
    cout << endl;
}

void preOrderTraversalIterative(Node *root){
    stack<Node *> st;
    st.push(root);

    Node *dummy;
    while (!st.empty())
    {
        dummy = st.top();
        cout << dummy->val << " ";
        if (dummy->left != nullptr)
        {
            st.push(dummy->left);
        }
        else
        {
            st.pop();
            if (dummy->right != nullptr)
                st.push(dummy->right);
            else if (!st.empty())
            {
                dummy = st.top();
                st.pop();
                if (dummy->right != nullptr)
                    st.push(dummy->right);
            }
        }
    }
    cout << endl;
}

void inOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}