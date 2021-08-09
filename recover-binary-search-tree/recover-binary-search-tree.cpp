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
    //Using Iterative Inorder Traversal Techq
    void recoverTree(TreeNode* root) 
    {
        TreeNode*first=NULL , *mid=NULL , *last=NULL , *prev=NULL;
        stack<TreeNode*>st;
        while(!st.empty() || root)
        {
            while(root)
            {
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            if(prev and prev->val>root->val)
            {
                if(!first)
                {
                    first=prev;
                    mid=root;
                }
                else
                    last=root;
            }
            prev=root;
            root=root->right;
        }
        //case 1 : when two swapped values are not adj to each other
        if(first and last)
            swap(first->val,last->val);
        //case 2 : when two swapped values are adj to each other
        else if(first and mid)
            swap(first->val,mid->val);
        return;
    }
};