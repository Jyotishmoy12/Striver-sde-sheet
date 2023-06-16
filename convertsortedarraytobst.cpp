TreeNode<int> *helper(vector<int> &arr, int start, int end)
{
    if(start > end)
        return NULL;
    int mid = (start+end)/2;
    TreeNode<int> *curr = new TreeNode<int> (arr[mid]);
    
    curr->left = helper(arr, start, mid-1);
    curr->right = helper(arr, mid+1, end);
    
    return curr;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    if(n==0)
    return NULL;
    return helper(arr, 0, n-1);
}