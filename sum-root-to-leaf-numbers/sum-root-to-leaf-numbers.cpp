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
    void func(TreeNode*root, int num , int&ans)
    {
        if(!root)
            return;
        if(root and !root->left and !root->right)
        {
            num=num*10+root->val;
            ans+=num;
            //cout<<num<<endl;
            num=0;
            return;   
        }
        num=num*10+root->val;
        //cout<<"NUM = "<<num<<endl;
        func(root->left,num,ans);
        func(root->right,num,ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        func(root,0,ans);
        return ans;
    }
};