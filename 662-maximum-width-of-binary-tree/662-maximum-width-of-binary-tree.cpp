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
    int widthOfBinaryTree(TreeNode* root) 
    {
        using ll = long long;
        queue<tuple<TreeNode*,ll,ll>>q;
        q.push({root,0,0});
        map<ll,vector<ll>>mp;
        while(!q.empty())
        {
            auto [node,lvl,NodeNum] = q.front();
            ll min = NodeNum;
            ll sz = q.size();
            
            while(sz--)
            {
                auto [node,lvl,NodeNum] = q.front();
                q.pop();
                NodeNum-=min;
                mp[lvl].push_back(NodeNum);
                if(node->left)
                    q.push({node->left,lvl+1,2*NodeNum+1});
                if(node->right)
                    q.push({node->right,lvl+1,2*NodeNum+2});
            }
            
        }
        
        ll ans = 0;
        for(auto &[lvl,vec]:mp)
        {
            // sort(vec.begin(),vec.end());
            int n = vec.size();
            ans = max(ans , vec[n-1]-vec[0]+1);
        }
        return ans;
        
        
    }
};