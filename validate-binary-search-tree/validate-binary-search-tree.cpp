#include<bits/stdc++.h>
using namespace std;

// struct TreeNode 
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;     
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
// };

class Solution 
{
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }

    bool isValidBST2(TreeNode* root , TreeNode*&prev) 
    {
        //Using inorder traversal
        if(root)
        {
            if(!isValidBST2(root->left,prev))
                return false;
                
            if(prev and prev->val >= root->val)
                return false;
                
            prev=root;
            
            return isValidBST2(root->right,prev);
        }
        return true;
    }
    bool isValidBST(TreeNode*root)
    {
        TreeNode*prev=NULL;
        return isValidBST2(root,prev);
    }
};