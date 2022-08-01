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
    
    unordered_map<int,int>mp;
    
    TreeNode*recur(vector<int>&pre, int& idx, int left, int right)
    {
        if(left>right || idx>=pre.size())
            return NULL;
        
        int pos = mp[pre[idx]];
        
        TreeNode*root = new TreeNode(pre[idx++]);
        root->left = recur(pre,idx,left,pos-1);
        root->right = recur(pre,idx,pos+1,right);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int n = preorder.size();
        vector<int>inorder = preorder;
        sort(inorder.begin(),inorder.end());
        for(int i=0; i<n; i++)
            mp[inorder[i]] = i;
        
        int idx = 0;
        TreeNode*ans = recur(preorder,idx,0,n-1);
        return ans;
        
    }
};