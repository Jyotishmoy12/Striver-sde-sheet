#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int dfsheight(BinaryTreeNode<int>* root){
        if(root==NULL) return 0;
        int leftheight=dfsheight(root->left);
        if(leftheight==-1) return -1;
        int rightheight=dfsheight(root->right);
        if(rightheight==-1) return -1;
        if(abs(leftheight-rightheight)>1) return -1;
        return max(leftheight,rightheight)+1;
    }
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
     return dfsheight(root)!=-1;
}
