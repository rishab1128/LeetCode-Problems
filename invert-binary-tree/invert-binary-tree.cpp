#include<bits/stdc++.h>
using namespace std;
​
// struct TreeNode 
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
​
class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
​
    void Swap( TreeNode **a , TreeNode **b) 
    { 
        TreeNode * temp = *a; 
        *a = *b; 
        *b = temp; 
    } 
​
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root)
        {
            Swap(&(root->left),&(root->right));
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};
​
