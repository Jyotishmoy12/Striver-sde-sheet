void solve(TreeNode<int>* root,int k,int& ans, int& index){
     if(root==NULL) return;
     solve(root->right,k,ans,index);
     index++;
     if(k==index){
         ans=root->data;
         return;
     }
     solve(root->left,k,ans,index);
 }
int KthLargestNumber(TreeNode<int>* root, int k) 
{
   int ans=-1,index=0;
   solve(root,k,ans,index); 
    return ans;
}
