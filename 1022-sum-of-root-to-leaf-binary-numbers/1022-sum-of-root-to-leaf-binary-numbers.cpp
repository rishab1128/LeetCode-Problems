#include<bits/stdc++.h>
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
    int ans=0;
    void helper(TreeNode*root,stack<int>st)
    {
        if(!root)
            return;
        st.push(root->val);
        if(!root->left&&!root->right)
        {
            int sum=0,i=0;
            while(!st.empty())
            {
                int x=st.top();
                st.pop();
                sum+=x*pow(2,i);
                i++;
            }
            ans+=sum;
        }
        if(root->left)
            helper(root->left,st);
        if(root->right)
            helper(root->right,st);
    }
    
    int sumRootToLeaf(TreeNode* root) 
    {
        stack<int>st;
        helper(root,st);
        return ans;
    }
};