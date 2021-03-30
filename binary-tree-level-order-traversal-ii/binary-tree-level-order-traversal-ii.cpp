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
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
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
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};