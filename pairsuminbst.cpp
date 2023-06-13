#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void inorderTraversal(BinaryTreeNode<int> *root,  vector<int>&traversal){
    if(root==NULL) return;
    inorderTraversal(root->left,traversal);
    traversal.push_back(root->data);
    inorderTraversal(root->right, traversal);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int>traversal;
    inorderTraversal(root, traversal);
    int left=0;
    int right=traversal.size()-1;
    while(left<right){
        if(traversal[left]+traversal[right]==k) return true;
        else if(traversal[left]+traversal[right]>k) right--;
        else
        left++;
    }
    return false;
}
