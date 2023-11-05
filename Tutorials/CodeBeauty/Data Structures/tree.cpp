#include <iostream>
using namespace std;

// Representing the node of a binary search tree
class Node
{
public:
    int value;
    Node *leftChild;
    Node *rightChild;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->value = data;
    newNode->leftChild = newNode->rightChild = nullptr;
    return newNode;
}

void printTreeInPreOrder(Node *root)
{
    if (root==nullptr) return ;
    cout << root->value << endl;
    printTreeInPreOrder(root->leftChild);
    printTreeInPreOrder(root->rightChild);
}
void printTreeInPostOrder(Node *root)
{
    if (root==nullptr) return ;
    printTreeInPostOrder(root->leftChild);
    printTreeInPostOrder(root->rightChild);
    cout << root->value << endl;
}
void printTreeInOrder(Node *root)
{
    if (root==nullptr) return ;
    printTreeInOrder(root->leftChild);
    cout << root->value << endl;
    printTreeInOrder(root->rightChild);
}

int main()
{
    Node *rootNode = createNode(1);
    rootNode->leftChild = createNode(2);
    rootNode->leftChild->leftChild = createNode(4);
    rootNode->leftChild->rightChild = createNode(5);
    rootNode->leftChild->rightChild->leftChild = createNode(9);
    rootNode->rightChild = createNode(3);
    rootNode->rightChild->leftChild = createNode(6);
    rootNode->rightChild->rightChild = createNode(7);
    rootNode->rightChild->rightChild->leftChild = createNode(15);

    // printTreeInPreOrder(rootNode);
    // printTreeInOrder(rootNode);
    printTreeInPostOrder(rootNode);
    return 0;
}

// Tree data structure is used to represent heirachy
//  Common Use Case: In different searching and sorting algorithms

// Building Block Of a Tree is called a Node(A singular entity)
// Lines connecting parent to child are called edges
// Childs cannot be connected in a tree(In graph , they can be connected)
// Root Node is a node that does not have a parent.Can be only one in a given tree
// Leaf Node is a node that does not have a child.Can be many leaf nodes in a given tree

// Regular Tree
// Binary Tree : Each parent cannot have more than two child nodes

// Binary Search Tree : same as binary tree except that its data is stored in a very specific way . The rule is that for a given parent , the left child node should have a value less than the parent and the right child node should have a value greater than the parent.
// BST facilitates the searching of elements

// Need for Tree Traversal : That is the only way to access the data which is stored inside the nodes and manipulate it.
// Traversal Algorithms : BFS(Breadth First Search)=>first searches the width of the tree And DFS(Depth First Search)=>first searches the depth of the tree

// DFS Algorithms:
// PreOrder(data,left,right)
// InOrder(left,data,right)
// PostOrder(left,right,data)
// e.g In the preOrder algorithm , we first manipulate the data , then we go to the left child ( then repeat the process )and then to the right child(and repeat the process).
// e.g In the InOrder algorithm , we first go to the left child(and repeat the process), then manipulate the data and then go to the right child(and repeat the process).

// In all the DFS Algorithms , whenever we visit a new node , we repeat the process


void printTreeInPreOrderMyWay(Node *root)
{
    cout << root->value << endl;
    if (root->leftChild != nullptr)
        printTreeInPreOrder(root->leftChild);
    if (root->rightChild != nullptr)
        printTreeInPreOrder(root->rightChild);
}