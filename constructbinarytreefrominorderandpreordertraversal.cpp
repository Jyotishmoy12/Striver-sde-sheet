#include<bits/stdc++.h>
void mapping(vector<int>& inorder,map<int,int>& nodetoindex)

{

    for(int i=0;i<inorder.size();i++)

    {

        nodetoindex[inorder[i]] = i;

    }

    return ;

}

TreeNode<int> * solve(vector<int>& inorder,vector<int>& preorder,int si,int ei,int& sp,int& ep,map<int,int>& mappin)

{

    if(si>ei || sp>=ep)

    {

        return NULL;

    }

    int element = preorder[sp++];

    TreeNode<int> * root = new TreeNode<int>(element);

    int position = mappin[element];

    //recursive call

    root->left = solve(inorder,preorder,si,position-1,sp,ep,mappin);

    root->right = solve(inorder,preorder,position+1,ei,sp,ep,mappin);

    return root;

    

}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)

{

    map<int,int> nodetoindex;

    mapping(inorder,nodetoindex);

    int ie = inorder.size()-1;

    int pres = 0;

    int pree = preorder.size();

    TreeNode<int>* ans = solve(inorder,preorder,0,ie,pres,pree,nodetoindex);

    return ans;

    

}
