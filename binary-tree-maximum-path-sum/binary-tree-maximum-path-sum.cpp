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
    int dfs(TreeNode*root, int&res)
    {
        if(!root)
            return 0;
        int l=dfs(root->left,res);
        int r=dfs(root->right,res);

        //max_thru_root ->stores the max path sum from root to any node
        int max_thru_root = max(max(l, r) + root->val , root->val);

        // overall_max --> represents the sum when the Node under consideration is the root of the maxsum path and no
        // ancestors of root are there in max sum path
        int overall_max = max({max_thru_root , l+root->val , r+root->val , l + r + root->val , root->val});


        res = max(res, overall_max); // Store the Maximum Result.

        return max_thru_root;
    }

    
    int maxPathSum(TreeNode* root) 
    {
        int res=INT_MIN;
        dfs(root,res);
        return res;
    }
};