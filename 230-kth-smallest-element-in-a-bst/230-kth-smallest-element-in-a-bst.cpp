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
    void inorder(TreeNode*root, int& ct, int k, int& ans)
    {
        stack<TreeNode*>st;
        while(root || st.size())
        {
            while(root)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            ct++;
            if(ct==k)
            {
                ans = root->val;
                return;
            }
            root = root->right;
        }
    }
    
    int kthSmallest(TreeNode* root, int k) 
    {
        int ans = -1 , ct = 0;
        inorder(root,ct,k,ans);
        return ans;
    }
};