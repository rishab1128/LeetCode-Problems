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
    int ht(TreeNode*root)
    {
        if(!root)
            return 0;
        return 1+max(ht(root->left) , ht(root->right));
    }
    
    TreeNode*LCA(TreeNode*root , int n1 , int n2)
    {
        if(!root)
            return NULL;
        
        if(root->val==n1 || root->val==n2)
            return root;
        
        TreeNode*left=LCA(root->left,n1,n2);
        TreeNode*right=LCA(root->right , n1,n2);
        
        if(left and right)
            return root;
        
        return (!left ? right : left);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        int h=ht(root);
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        vector<vector<TreeNode*>>res(h);
        while(q.size() >0)
        {
            TreeNode*node=q.front().first;
            int lvl=q.front().second;
            q.pop();
            res[lvl].push_back(node);
            if(node->left)
                q.push({node->left , lvl+1});
            if(node->right)
                q.push({node->right , lvl+1});
        }
        
        // for(int i=0; i<h; i++)
        // {
        //     cout<<i<<" ----> ";
        //     for(auto x: res[i])
        //         cout<<x->val<<" ";
        //     cout<<endl;
        // }
        
        int sz=res[h-1].size() ;
        
        int left_most_deepest_leaf=res[h-1][0]->val;
        int right_most_deepest_leaf=res[h-1][sz-1]->val;
        
        TreeNode*ans=LCA( root, left_most_deepest_leaf , right_most_deepest_leaf );
        
        return ans;
        
    }
};