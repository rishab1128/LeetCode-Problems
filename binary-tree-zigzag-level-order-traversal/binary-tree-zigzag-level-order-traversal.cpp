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
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if (root == NULL) 
        {
            return vector<vector<int> > ();
        }
        
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        bool l2r=true;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>row(sz);
            for(int i=0; i<sz; i++)
            {
                TreeNode*node=q.front();
                q.pop();
                
                if(l2r)
                    row[i]=node->val;
                else
                    row[sz-1-i]=node->val;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
            }
            l2r=!l2r;
            ans.push_back(row);
        }
        return ans;
        
    }
};