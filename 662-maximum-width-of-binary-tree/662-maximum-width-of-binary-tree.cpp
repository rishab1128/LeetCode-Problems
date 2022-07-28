/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     ll val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(ll x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(ll x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //O-based -> left child = 2*i+1 , right child = 2*i+2;
    //1-based -> left child = 2*i+1 , right child = 2*i+2;
    
    int widthOfBinaryTree(TreeNode* root) 
    {
        using ll = long long;
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        ll prevMini = 0 , ans = 0;
        while(!q.empty())
        {
            ll sz = q.size();
            ll mini = INT_MAX;
            ll start = INT_MAX , end = INT_MIN;
            while(sz--)
            {
                auto [node, i] = q.front();
                q.pop();
                i -= prevMini;
                if(node->left)
                {
                    q.push({node->left,2*i+1});
                    mini = min(mini,2*i+1);
                }
                if(node->right)
                {
                    q.push({node->right,2*i+2});
                    mini = min(mini,2*i+2);
                }
                start = min(start,i);
                end = max(end,i);
            }
            prevMini = mini;
            ans = max(ans,end-start+1);
        }
        return ans;
    }
};