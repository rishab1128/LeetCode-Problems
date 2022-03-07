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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) 
    {
        map<int,TreeNode*>mp;
        unordered_map<int,int>children;
        for(auto arr : desc)
        {
            int par=arr[0] , child=arr[1] , isLeft=arr[2];
            if(mp.find(par)==mp.end())
            {
                TreeNode*node=new TreeNode(par);
                mp[par]=node;
            }
            if(mp.find(child)==mp.end())
            {
                TreeNode*childNode=new TreeNode(child);
                mp[child]=childNode;
            }
            if(isLeft)
                mp[par]->left=mp[child];
            else
                mp[par]->right=mp[child];
            
            children.insert({child,1});
        }
        int ans=-1;
        for(auto arr: desc)
        {
            int par=arr[0] , child=arr[1];
            if(children[par]==0)
            {
                ans=par;
                break;
            }
        }
        
        return mp[ans];
    }
};