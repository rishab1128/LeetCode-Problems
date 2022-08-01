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

//Preorder -> VLR
//TC : O(N)
//SC : O(N)

class Solution {
public:
    
    TreeNode* recur(vector<int>&preorder, int& idx, int upperBound)
    {
       if(idx>=preorder.size() || preorder[idx]>upperBound)
           return NULL;
        
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = recur(preorder,idx,root->val);
        root->right = recur(preorder,idx,upperBound);
        return root;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int idx = 0;
        TreeNode* ans = recur(preorder,idx,INT_MAX);
        return ans;
    }
};