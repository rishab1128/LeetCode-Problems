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
    void inorder(TreeNode*root, int& ct, int k, int& ans)
    {
        if(root)
        {
            inorder(root->left,ct,k,ans);
            ct++;
            if(ct==k)
            {
                ans = root->val;
                return;
            }
            inorder(root->right,ct,k,ans);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) 
    {
        int ans = -1 , ct = 0;
        inorder(root,ct,k,ans);
        return ans;
    }
};