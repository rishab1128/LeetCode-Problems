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
    
    vector<TreeNode*> recur(int low, int high)
    {
        vector<TreeNode*> ans;
        if(low>high) 
        {
            ans.push_back(NULL);
            return ans;
        }
        
        for(int i = low; i <= high; i++)
        {
            vector<TreeNode*> left = recur(low,i-1);
            vector<TreeNode*> right = recur(i+1,high);
            
            for(TreeNode* leftNode : left) 
            {
                for(TreeNode* rightNode : right)
                {
                    TreeNode* newNode = new TreeNode(i, leftNode, rightNode);
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