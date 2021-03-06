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
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    int height(TreeNode*root)
    {
        int ans=0;
        if(!root)
            return 0;
        else
        {
            int left=height(root->left);
            int right=height(root->right);
            ans=max(left,right)+1;
        }
        return ans;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<pair<TreeNode*,int>>q;
        int h=height(root);
        if(h==0)
            return {};
        //cout<<h<<endl;
        vector<vector<int>>ans(h);
        q.push({root,0});
        while(!q.empty())
        {
            TreeNode*node=q.front().first;
            int lvl=q.front().second;
            //cout<<node->val<<" "<<lvl<<endl;
            ans[lvl].push_back(node->val);
            q.pop();
            if(node->left)
                q.push({node->left,lvl+1});
            if(node->right)
                q.push({node->right,lvl+1});
        }
        
        return ans;
    }
    
    long long sum(vector<int>ans)
    {
        long long sum=0;
        for(auto x: ans)
            sum+=x;
        return sum;
    }
    
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<vector<int>>ans=levelOrder(root);
        
        // for(auto v: ans)
        //     for(auto x: v)
        //         cout<<x<<" ";
        // cout<<endl;
        
        vector<double>res(ans.size());
        for(int i=0; i<ans.size(); i++)
        {
            int sz=ans[i].size();
            res[i]=(double)sum(ans[i])/sz; 
        }
        return res;
        
    }
};