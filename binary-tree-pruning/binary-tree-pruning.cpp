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
    //Exact Same Ques as LC-1325-Delete Leaves with a given value only difference is that here target = 0 is pre-defined 
    TreeNode* pruneTree(TreeNode* root) {
        if(root->left)
            root->left=pruneTree(root->left);
        if(root->right)
            root->right=pruneTree(root->right);
        if(root and root->val==0 and !root->left and !root->right)
            return NULL;
        return root;
    }
};