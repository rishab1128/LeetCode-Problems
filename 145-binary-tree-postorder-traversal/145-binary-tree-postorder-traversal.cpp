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
//Postorder -> LRV
//Iterative using only 1 stack
//TC : O(2*n)
//SC : O(n)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(!root)
            return {};
        
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode*curr = root;
        while(curr!=NULL || !st.empty())
        {
            if(curr!=NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                TreeNode*tmp = st.top()->right;
                if(tmp==NULL)
                {
                    tmp = st.top();
                    st.pop();
                    ans.push_back(tmp->val);
                    while(st.size() and tmp==st.top()->right)
                    {
                        tmp = st.top();
                        st.pop();
                        ans.push_back(tmp->val);
                    }
                }
                else
                    curr = tmp;
            }
        }
        
        return ans;
        
    }
};