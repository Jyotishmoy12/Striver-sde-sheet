#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
    void postorder(TreeNode* root, vector<int>& sol) {
        if (!root)
            return;
        postorder(root->left, sol);
        postorder(root->right, sol);
        sol.push_back(root->data);
    }
vector<int> getPostOrderTraversal(TreeNode *root)
{  
       vector<int> sol;
        postorder(root, sol);
        return sol;
}
