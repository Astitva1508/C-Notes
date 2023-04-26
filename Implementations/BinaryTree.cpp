#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

TreeNode* insertIntoTree(TreeNode* root, int element);
void levelOrder(TreeNode* node);
void traverseInorder(TreeNode *root);
TreeNode *findInorderPredecessor(TreeNode *node);
TreeNode* deleteFromTree(TreeNode *root,int element);


int main(){
    TreeNode *root =nullptr;
    int n;
    cin>>n;
    int x;
    while(n--) {
        cin>>x;
        root = insertIntoTree(root,x);
    }
    int y;
    cin>>y;
    root = deleteFromTree(root,y);
    levelOrder(root);
    traverseInorder(root);
    return 0;
}



void traverseInorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    traverseInorder(root->left);
    cout << root->val << " ";
    traverseInorder(root->right);
}

void levelOrder(TreeNode *node)
{
    if (node == nullptr)
        return;
    queue<TreeNode *> q;
    q.push(node);
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
    cout<<endl;
}

TreeNode *insertIntoTree(TreeNode *root, int element)
{
    if (root == nullptr)
        return new TreeNode(element);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            TreeNode *x = q.front();
            q.pop();
            if (x->left)
                q.push(x->left);
            else
            {
                x->left = new TreeNode(element);
                return root;
            }
            if (x->right)
                q.push(x->right);
            else
            {
                x->right = new TreeNode(element);
                return root;
            }
        }
    }
    return root;
}

TreeNode *findInorderPredecessor(TreeNode *node)
{

    node = node->left;
    while (node->right != nullptr)
        node = node->right;
    return node;
}

TreeNode *deleteFromTree(TreeNode *root, int element)
{
    if (root == nullptr)
        return nullptr;

    if (root->val == element)
    {
        TreeNode *x = nullptr;
        if (root->left && !root->right)
        {
            x = root->left;
            delete root;
            return x;
        }
        else if (root->right && !root->left)
        {
            x = root->right;
            delete root;
            return x;
        }
        else if (!root->left && !root->right)
        {
            delete root;
            return x;
        }
        else
        {
            x = findInorderPredecessor(root);
            int y = x->val;
            root = deleteFromTree(root, y);
            root->val = y;
            return root;
        }
    }
    else
    {
        root->left = deleteFromTree(root->left, element);
        root->right = deleteFromTree(root->right, element);
    }
    return root;
}