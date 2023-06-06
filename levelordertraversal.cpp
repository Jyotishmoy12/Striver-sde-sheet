vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    if(root==NULL){
        return {};
    }

    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    vector<int>ans;
    
    while(!q.empty()){
        BinaryTreeNode<int> *temp = q.front();
        ans.push_back(temp->val);

        q.pop();
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);

    }
    return ans;
}
