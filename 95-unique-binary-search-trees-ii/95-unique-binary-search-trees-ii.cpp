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
    
    vector<TreeNode*> recur(int i, int j)
    {
        vector<TreeNode*> ans;
        if(i>j) 
        {
            ans.push_back(NULL);
            return ans;
        }
        
        for(int it = i; it <= j; it++)
        {
            auto left = recur(i,it-1);
            auto right = recur(it+1,j);
            for(auto l : left) {
                for(auto r : right){
                    TreeNode* newNode = new TreeNode(it, l, r);
                    ans.push_back(newNode);
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) 
    {
        return recur(1,n);
    }
};