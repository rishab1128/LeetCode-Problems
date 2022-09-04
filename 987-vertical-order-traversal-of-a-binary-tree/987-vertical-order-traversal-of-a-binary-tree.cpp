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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        map<int,vector<int>>mp;
        while(q.size()>0)
        {
            int sz=q.size();
            multiset<pair<int,int>>st;
            while(sz--)
            {
                TreeNode*node=q.front().first;
                int col=q.front().second;
                st.insert({col,node->val});
                q.pop();
                if(node->left)
                    q.push({node->left,col-1});
                if(node->right)
                    q.push({node->right,col+1});
            }
            for(auto ele : st)
            {
                int col=ele.first;
                mp[col].push_back(ele.second);
            }
        }
        
        vector<vector<int>>ans;
        for(auto x: mp)
            ans.push_back(x.second);
        
        return ans;
    }
};