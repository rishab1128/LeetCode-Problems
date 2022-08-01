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
    bool isValidBST(TreeNode* root , long long mini = LLONG_MIN , long long maxi = LLONG_MAX) 
    {
        if(!root)
            return true;
        if(root and root->val<=mini) 
            return false;
        if(root and root->val>=maxi) 
            return false;
        return isValidBST(root->left,mini,root->val) and isValidBST(root->right,root->val,maxi);
    }
};