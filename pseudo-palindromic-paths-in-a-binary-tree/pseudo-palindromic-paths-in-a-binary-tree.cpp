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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    //Using Bit-wise trick to check if path is pseudo - palindrome or not 
    //Refer Solution for more details
    
    void func(TreeNode*root, int path , int&ct)
    {
        if(!root)
            return;
        
        if(root)
        {
            path=path^(1<<root->val); // Note : 1<<x = 2^x ;
            func(root->left,path,ct);
            func(root->right,path,ct);
        }
        
        if(root and !root->left and !root->right)
        { 
            if((path & (path-1))==0)
                ct+=1;
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        int ct=0;
        func(root,0,ct);
        return ct;
    }
};