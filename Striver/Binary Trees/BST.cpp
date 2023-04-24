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

TreeNode *insertBST(TreeNode *root, int element);
TreeNode *deleteBST(TreeNode *root, int element);
TreeNode *findInorderPredecessor(TreeNode *node);
void traverseInorder(TreeNode *root);
void traverseLevelOrder(TreeNode *root);

int main()
{

    // TreeNode *root = new TreeNode(5);
    // // root->left = new TreeNode(3);
    // // root->left->left = new TreeNode(2);
    // // root->left->right = new TreeNode(4);
    // // root->left->left->left = new TreeNode(8);
    // // root->right = new TreeNode(6);
    // // root->right->left = new TreeNode(7);
    // // root->right->right = new TreeNode(7);

    int n;
    cin >> n;
    TreeNode *root = nullptr;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        root = insertBST(root, x);
    }
    int y;
    cin>>y;
    traverseLevelOrder(root);
    deleteBST(root,y);
    traverseLevelOrder(root);
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

void traverseLevelOrder(TreeNode* root){
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
    cout<<endl;
}

TreeNode *insertBST(TreeNode *root, int element)
{
    if (root == nullptr)
        return root = new TreeNode(element);

    if (root->val > element)
        root->left = insertBST(root->left, element);
    else
        root->right = insertBST(root->right, element);

    return root;
}

TreeNode *findInorderPredecessor(TreeNode *node)
{
    if (node == nullptr)
        return nullptr;
    node = node->left;
    while (node->right != nullptr)
        node = node->right;
    return node;
}

TreeNode *deleteBST(TreeNode *root, int element)
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
        else if (root->left && !root->right){
            TreeNode*x = root->left;
            delete root;
            return x;
        }
        else if (!root->left && root->right){
            TreeNode *x = root->right;
            delete root;
            return x;
        }
        else
        {
            TreeNode*desired = findInorderPredecessor(root);
            int x = desired->val;
            root = deleteBST(root,x);
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