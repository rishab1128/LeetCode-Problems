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


// -1 to represent that node is not covered.
//  0 to represent the node is having camera
//  1 to represent the node is already covered.


class Solution {
public:
    int camera=0;
    
    int solve(TreeNode *root)
    {
        if(!root)
            return 1;
        int lc=solve(root->left);
        int rc=solve(root->right);
        if(lc==-1 or rc==-1)
        {
            camera++;
            return 0;
        }
        if(lc==0 or rc==0)
            return 1;
        return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        camera=0;
        if(solve(root)==-1)
            camera++;
        return camera;
    }
};