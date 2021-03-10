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
    void func(TreeNode*root, int currMax, int currMin , int&ans)
    {
        if(!root)
            return;
        int poss_ans=max(abs(root->val-currMax),abs(root->val-currMin));
        ans=max(ans,poss_ans);
        currMax=max(root->val,currMax);
        currMin=min(root->val,currMin);
        func(root->left,currMax,currMin,ans);
        func(root->right,currMax,currMin,ans);
    }
    int maxAncestorDiff(TreeNode* root) 
    {
        int ans=0;
        func(root,root->val,root->val,ans);
        return ans;
    }
};