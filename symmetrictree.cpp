bool solve(BinaryTreeNode<int>*r1,BinaryTreeNode<int>*r2){
   if(r1==NULL && r2==NULL) return true;
    else if(r1==NULL || r2==NULL || r1->data!=r2->data){
        return false;
    }
    return solve(r1->right, r2->left) && solve(r1->left, r2->right);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{   
    if(root==NULL) return -1;
    return solve(root->left,root->right);   
}
