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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
  vector<int> ans;

    // edge case 

    if(!root)

    return ans;

 

    queue<BinaryTreeNode<int> *> q;

    q.push(root);

    bool lefttoright = true;

    

 

    while(!q.empty())

    {

        int size = q.size();

        vector<int> row(size);

 

        for (int i = 0; i < size; i++) {

          BinaryTreeNode<int> *temp = q.front();

          q.pop();

 

          int index = (lefttoright) ? i : (size - 1 - i); // if true then insert it from the front and if false insert it from the back i.e in reverse order

 

          row[index] = temp->data;

 

          if (temp->left)

            q.push(temp->left);

          if (temp->right)

            q.push(temp->right);

        }

        ans.insert(ans.end(), row.begin(), row.end());

        lefttoright = !(lefttoright);

    }

 

    return ans;
}
