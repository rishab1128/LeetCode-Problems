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
    
    
    TreeNode*LCA(TreeNode*root , int start , int dest)
    {
        if(!root)
            return NULL;
        
        if(root->val==start || root->val==dest)
            return root;
        
        TreeNode*left=LCA(root->left , start, dest);
        TreeNode*right=LCA(root->right , start, dest);
        
        if(left and right)
            return root;
        
        return right==NULL ? left : right;
    }
    
    bool getPath(TreeNode*lca , string& s , int end)
    {
        if(!lca)
            return false;
        
        if(lca->val==end)
            return true;
        
        s+='L';
        if(!getPath(lca->left , s, end))
            s.pop_back();
        else
            return true;
        
        s+='R';
        if(!getPath(lca->right , s, end))
            s.pop_back();
        else
            return true;
        
        return false;
    }
    
    string getDirections(TreeNode* root, int start, int dest)
    {
     
        TreeNode*lca=LCA(root,start,dest);
       
        string s1="",s2="";
        getPath(lca,s1,start);
        getPath(lca,s2,dest);
        
        for(auto &x:s1)
            x='U';
        
        return s1+s2;
    }
};