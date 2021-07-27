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
    void func(TreeNode*root ,  int&ans)
    {
       queue<pair<TreeNode*,int>>q;
       q.push({root,1});
       while(q.size()>0)
       {
            TreeNode*node=q.front().first;
            int level=q.front().second;
            q.pop();
            if(node->left)
                q.push({node->left,level+1});
            if(node->right)
                q.push({node->right,level+1});
            else if(!node->left and !node->right)
                ans=min(ans,level);
       }
    }

    int minDepth(TreeNode* root) 
    {
        if(!root)
            return 0;
        int ans=INT_MAX;
        func(root,ans);
        return ans;
    }
};