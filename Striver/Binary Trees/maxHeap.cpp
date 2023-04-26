#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    int height;
    TreeNode() : val(0), left(nullptr), right(nullptr), height(1){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), height(1){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right), height(1){};
};

void traverseInorder(TreeNode *root);
void levelOrder(TreeNode *node);

void balanceHeap(TreeNode *root)
{
    if(root==nullptr) return;
    balanceHeap(root->left);
    balanceHeap(root->right);

    while(true){
        if (!root->right && !root->left) return;
        int leftVal = root->left?root->left->val:INT_MIN;
        int rightVal = root->right?root->right->val:INT_MIN;

        if(leftVal>rightVal && leftVal>root->val){
            swap(root->left->val,root->val);
            root = root->left;
        }else if(rightVal>leftVal && rightVal>root->val){
            swap(root->right->val,root->val);\
            root = root->right;
        }else{
            return;
        }
    }
}

TreeNode * insertHeap(TreeNode *root, int element)
{
    if(root==nullptr) return new TreeNode(element);
    queue<TreeNode*> q;
    q.push(root);
    bool isInserted = false;
    while(!q.empty() && !isInserted){
        int size = q.size();
        while(size--){
            TreeNode *x = q.front();
            q.pop();
            if(x->left) q.push(x->left);
            else{
                x->left = new TreeNode(element);
                isInserted = true;
                break;
            }

            if(x->right) q.push(x->right);
            else{
                x->right = new TreeNode(element);
                isInserted = true;
                break;
            }
        }
    }
    return root;
}

int main()
{
    TreeNode *root = nullptr;
    int n;
    cin>>n;
    int x;
    while(n--){
        cin>>x;
        root = insertHeap(root,x);
    }
    balanceHeap(root);
    levelOrder(root);
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
    cout << endl;
}