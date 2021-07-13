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
class FindElements {
public:
    TreeNode*root2=NULL;
    FindElements(TreeNode* root) 
    {
        root->val=0;
        recover(root);
        root2=root;
    }
    
    void recover(TreeNode*root)
    {
        if(!root)
            return ;
        if(root->left)
            root->left->val=(root->val)*2+1;
        if(root->right)
            root->right->val=(root->val)*2+2;
        recover(root->left);
        recover(root->right);
    }
    
    bool find2(int target , TreeNode*root2)
    {
        if(!root2)
            return false;
        if(root2->val==target)
            return true;
        return find2(target,root2->left) || find2(target,root2->right);
    }
    
    bool find(int target) 
    {
        return find2(target,root2);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */