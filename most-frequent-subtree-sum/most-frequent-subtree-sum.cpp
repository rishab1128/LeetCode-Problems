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
    map<int,int>mp;
    map<TreeNode*,int>mp2;
    int dfs(TreeNode*root)
    {
        if(!root)
            return 0;
        if(mp2[root]==0)
        {
            mp2[root]=1;
            mp[root->val+dfs(root->left)+dfs(root->right)]++;
        }
        
        return root->val+dfs(root->left)+dfs(root->right);
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        mp.clear();
        mp2.clear();
        int sum=dfs(root) , maxi_freq=0;
        vector<int>ans;
        for(auto x: mp)
        {
            //cout<<x.first<<" "<<x.second<<endl;
            maxi_freq=max(maxi_freq,x.second);
        }
        for(auto x: mp)
        {
            if(x.second==maxi_freq)
                ans.push_back(x.first);
        }
            
        //cout<<"-------------------"<<endl;
        
        return ans;
    }
};