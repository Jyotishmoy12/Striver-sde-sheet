void solve(BinaryTreeNode<int>*root,int key,int &pre,int &suc)
{
       if(root==NULL)
        {
            return;
        }
       solve(root->left,key,pre,suc);
        if(root->data<key)
        {
            pre=root->data;
        }
        if(root->data>key and suc==-1)
        {
            suc=root->data;
        }
       solve(root->right,key,pre,suc);
      
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int pre=-1;
    int suc=-1;
    if(root==NULL)
    {
      return {-1, -1};
    }
    solve(root,key,pre,suc);
    return {pre,suc};
}
