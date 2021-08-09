/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //Traversing the BST in an inorder fashion
    void helper(TreeNode*root , TreeNode**first , TreeNode**mid , TreeNode**last , TreeNode**prev)
    {
        if(!root)
            return;

        helper(root->left,first,mid,last,prev);

        if((*prev) and root->val<(*prev)->val)
        {
            if(!(*first))
            {
                *first=*prev;
                *mid=root;
            }
            else
            {
                *last=root;
            }
        }
        *prev=root;
        helper(root->right,first,mid,last,prev);
    }

    void recoverTree(TreeNode*root){

        TreeNode*first=NULL,*last=NULL,*mid=NULL,*prev=NULL;

        helper(root,&first,&mid,&last,&prev);

        //case 1 -> when swapped elements are not adj to each other
        if(first and last)
            swap(first->val,last->val);

        //case 2 -> when swapped elements are adj to each other
        else if(first and mid)
            swap(first->val,mid->val);

        return;
    }
    
    
};