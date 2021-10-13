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
    map<int,int>mp;

    TreeNode*helper(vector<int>&pre , vector<int>&ino , int&i , int left , int right)
    {
        if(left>right || i>=pre.size())
            return NULL;
        int pos=mp[pre[i]];
        TreeNode*root=new TreeNode(pre[i++]);
        root->left=helper(pre,ino,i,left,pos-1);
        root->right=helper(pre,ino,i,pos+1,right);
        return root;
    }

    TreeNode*bstFromPreorder(vector<int>&pre)
    {
        int n=pre.size();
        vector<int>ino=pre;
        sort(ino.begin() , ino.end());
        mp.clear();
        for(int i=0; i<n; i++)
            mp[ino[i]]=i;
        int i=0;
        return helper(pre,ino,i,0,n-1);
    }

};