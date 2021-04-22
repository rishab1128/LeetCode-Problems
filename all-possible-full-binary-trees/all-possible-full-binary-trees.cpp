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
    unordered_map<int,vector<TreeNode*>>mp;
    
    vector<TreeNode*> allPossibleFBT(int n) 
    {
        vector<TreeNode*>ans;
        if(n==1)
        {
            TreeNode*root=new TreeNode();
            ans.push_back(root);
            return ans;
        }
        if(n<1 || n%2==0)
            return {};
        
        if(mp.find(n)!=mp.end())
            return mp[n];
        
        for(int i=1; i<n-1; i+=2)
        {
            vector<TreeNode*>left=allPossibleFBT(i);
            vector<TreeNode*>right=allPossibleFBT(n-i-1);
            for(auto l:left)
            {
                for(auto r: right)
                {
                    TreeNode*root=new TreeNode();
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        mp[n]=ans;
        return ans;
    }
};