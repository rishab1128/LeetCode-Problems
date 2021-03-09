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
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    void func(TreeNode*root, unordered_map<int,int>&mp, int&ct)
    {
        if(!root)
            return;
        
        if(root)
        {
            mp[root->val]++;
            func(root->left,mp,ct);
            func(root->right,mp,ct);
            mp[root->val]--;
        }
        
        if(root and !root->left and !root->right)
        {
            int tmp=0;
            mp[root->val]++;
            for(auto x: mp)
            {
                if(mp[x.first]%2)
                    tmp++;
                if(tmp>1)
                    break;
            }
            if(tmp<=1)
                ct+=1;
            mp[root->val]--;
            return;
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        unordered_map<int,int>mp;
        int ct=0;
        func(root,mp,ct);
        return ct;
    }
};