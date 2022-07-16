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

//Preorder -> VLR
//Iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(!root)
            return {};
        vector<int>ans;
        stack<TreeNode*>st;
        while(root || !st.empty())
        {
            while(root)
            {
                ans.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            root = root->right;
        }
        return ans;
        
    }
};