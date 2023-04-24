#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    int height;
    TreeNode() : val(0), left(nullptr), right(nullptr),height(1){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), height(1){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right), height(1){};
};

void levelOrder(TreeNode *node);
void traverseInorder(TreeNode *root);
void traversePreOrder(TreeNode *root);
TreeNode *findInorderPredecessor(TreeNode *node);
int height(TreeNode *root);
int getBalanceFactor(TreeNode *root);

TreeNode *rightRotate(TreeNode * parent)
{
    TreeNode *x = parent->left;
    TreeNode *y = x->right;
    x->right = parent;
    parent->left = y;

    x->height = max(height(x->left),height(x->right))+1;
    parent->height = max(height(parent->left),height(parent->right))+1;

    return x;
}

TreeNode *leftRotate(TreeNode*parent){
    TreeNode *x = parent->right;
    TreeNode *y = x->left;
    x->left = parent;
    parent->right = y;

    x->height = max(height(x->left), height(x->right)) + 1;
    parent->height=max(height(parent->right),height(parent->left))+1;

    return x;
}

TreeNode *insertAVL(TreeNode *root, int element)
{
    if (root == nullptr)
        return (new TreeNode(element));

    if (root->val > element)
    {
        root->left = insertAVL(root->left, element);
    }
    else
    {
        root->right = insertAVL(root->right, element);
    }
    int z = getBalanceFactor(root);
    if (z > 1)
    {
        if (element>root->right->val)
        {
            root = leftRotate(root);
        }
        else
        {
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
    }
    else if (z < -1)
    {
        if (element<root->left->val)
        {
            root = rightRotate(root);
        }
        else
        {
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
    }
    root->height = max(height(root->right), height(root->left)) + 1;
    return root;
}


int main()
{
    TreeNode*root = insertAVL(root,10);
    root= insertAVL(root,20);
    root= insertAVL(root,30);
    root= insertAVL(root,40);
    root= insertAVL(root,50);
    root= insertAVL(root,25);
    return 0;
}

void traverseInorder(TreeNode * root)
{
    if (root == nullptr)
        return;
    traverseInorder(root->left);
    cout << root->val << " ";
    traverseInorder(root->right);
}

void traversePreOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    traversePreOrder(root->left);
    traversePreOrder(root->right);
}

void traverseLevelOrder(TreeNode * root)
{
    if (root == nullptr)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            TreeNode *x = q.front();
            q.pop();
            cout << x->val << " ";
            if (x->left)
                q.push(x->left);
            if (x->right)
                q.push(x->right);
        }
    }
    cout << endl;
}

TreeNode *findInorderPredecessor(TreeNode * node)
{
    if (node == nullptr)
        return nullptr;
    node = node->left;
    while (node->right != nullptr)
        node = node->right;
    return node;
}

TreeNode *deleteBST(TreeNode * root, int element)
{
    if (root == nullptr)
        return nullptr;
    if (root->val == element)
    {
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }
        else if (root->left && !root->right)
        {
            TreeNode *x = root->left;
            delete root;
            return x;
        }
        else if (!root->left && root->right)
        {
            TreeNode *x = root->right;
            delete root;
            return x;
        }
        else
        {
            TreeNode *desired = findInorderPredecessor(root);
            int x = desired->val;
            root = deleteBST(root, x);
            root->val = x;
            return root;
        }
    }

    if (root->val > element)
        root->left = deleteBST(root->left, element);
    else
        root->right = deleteBST(root->right, element);

    return root;
}

int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return root->height;
}

int getBalanceFactor(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return height(root->right) - height(root->left);
}

