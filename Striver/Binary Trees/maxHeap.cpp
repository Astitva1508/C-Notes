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



TreeNode* insertHeap(TreeNode* root,int element){
    if(root==nullptr) return new TreeNode(element);
    queue<TreeNode*> q;
    q.push(root);
    bool isInserted = false;
    while(!q.empty() && !isInserted){
        int size = q.size();
        while(size--){
            TreeNode *x = q.front();
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
}

int main()
{

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