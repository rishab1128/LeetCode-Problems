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
    vector<pair<int,int>>leaves;
    void leaf_nodes(TreeNode*root,int level)
    {
        if(root!=nullptr&&root->left==nullptr&&root->right==nullptr)
        {
            leaves.push_back(make_pair((root->val),level));
            return;
        }
        if(root->left!=nullptr)
            leaf_nodes(root->left,level+1);
        if(root->right!=nullptr)
            leaf_nodes(root->right,level+1);
    }
    int deepestLeavesSum(TreeNode* root) 
    {
        int sum=0,maxi=0;
        leaf_nodes(root,0);
        for(auto x: leaves)
            maxi=max(maxi,x.second);
        for(auto x: leaves)
        {
            if(x.second==maxi)
                sum+=x.first;
        }
        return sum;
    }
};