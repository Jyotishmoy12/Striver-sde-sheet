TreeNode<int>* mark_parents(TreeNode<int>* node, int start, unordered_map<TreeNode<int>*,TreeNode<int>*>& parents)
{
    TreeNode<int>* res;
    queue<TreeNode<int>*> q;
    q.push(node);
    while(!q.empty()) {
        TreeNode<int>* node = q.front();
        q.pop();
        if(node->data == start) res = node;
        if(node->left) {
            q.push(node->left);
            parents[node->left] = node;
        }
        if(node->right) {
            q.push(node->right);
            parents[node->right] = node;
        }
    }
    return res;
}


TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    if(root == NULL) return NULL;
    unordered_map<TreeNode<int>*, TreeNode<int>*> parent;
    leaf = mark_parents(root, leaf->data, parent);
    TreeNode<int>* cur = leaf;
    while(parent[cur]) {
        TreeNode<int>* pCur = parent[cur];
        if(pCur->left == cur) {
            pCur->left = NULL;
        } else {
            pCur->right = pCur->left;
            pCur->left = NULL;
        }
        cur->left = pCur;
        cur = pCur;
    }
    return leaf;
}
