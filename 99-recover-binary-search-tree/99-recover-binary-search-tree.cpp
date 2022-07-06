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
    TreeNode*node1 , *node2 , *prev;
    
    void inorder(TreeNode*curr)
    {
        if(!curr)
            return;
        inorder(curr->left);
        if(prev and prev->val>curr->val){
            if(!node1)
                node1=prev;
            node2=curr;
        }
        prev=curr;
        inorder(curr->right);
    }
    
    void recoverTree(TreeNode* root) 
    {
        node1=NULL , node2=NULL , prev=NULL;
        inorder(root);
        int tmp = node1->val;
        node1->val = node2->val;
        node2->val=tmp;
        
        return;
    }
};