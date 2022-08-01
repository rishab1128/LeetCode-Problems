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
struct Node
{
    int maxi,mini,sum;
    Node(int maxi , int mini , int sum)
    {
        this->maxi = maxi;
        this->mini = mini;
        this->sum = sum;
    }
};
class Solution {
public:
    
    Node bottomUp(TreeNode*root, int& ans)
    {
        if(!root)
        {
            Node node(INT_MIN , INT_MAX , 0);
            return node;
        }
        if(root and !root->left and !root->right) //A single node can always be a BST
        {
            Node node(root->val, root->val, root->val);
            ans = max(ans , node.sum);
            return node;
        }
        
        auto left = bottomUp(root->left , ans);
        auto right = bottomUp(root->right, ans);
        
        //Check for BST
        if(root->val > left.maxi and root->val < right.mini)
        {
            Node node(max(right.maxi , root->val) , min(left.mini,root->val) , root->val+left.sum+right.sum); //Node can be a valid BST root
            ans = max(ans , node.sum);
            return node;
        }
        
        Node node(INT_MAX,INT_MIN,0); //Node cannot be a valid BST root
        return node;
    }
    
    int maxSumBST(TreeNode* root) 
    {
        int ans = 0;
        bottomUp(root,ans);
        return ans;
    }
};