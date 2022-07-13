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
    
    unordered_map<TreeNode*,int>diameter; //diameter[i] = what is the diameter if path passes through node i 
    unordered_map<TreeNode*,int>downPath; //downPath[i] = longest simple path in subtree rooted at i that starts at i
    
    void calDownPath(TreeNode*node)
    {
        if(!node)
            return;
        
        int bestChildDownPath = 0;
        bool leaf = 1;
        
        if(node->left)
        {
            leaf=0;
            calDownPath(node->left);
            bestChildDownPath = max(bestChildDownPath , downPath[node->left]);
        }
        if(node->right)
        {
            leaf=0;
            calDownPath(node->right);
            bestChildDownPath = max(bestChildDownPath , downPath[node->right]);
        }
        
        if(leaf)
            downPath[node] = 0;
        else
            downPath[node]=1+bestChildDownPath;
    }
    
    void calDiameter(TreeNode*node)
    {
        vector<int>children;
        if(node->left)
        {
            calDiameter(node->left);
            children.push_back(downPath[node->left]);
        }
        if(node->right)
        {
            calDiameter(node->right);
            children.push_back(downPath[node->right]);
        }
    
        
        if(children.size()==0)
            diameter[node] = 0;
        else if(children.size()==1)
            diameter[node]=1+children[0];
        else
            diameter[node] = 2+children[0]+children[1];
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        calDownPath(root);
        calDiameter(root);
        int ans = 0;
        for(auto [node,dia] : diameter)
            ans = max(ans,dia);
        
        return ans;
    }
};