#include<bits/stdc++.h>
using namespace std;

/*struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};*/

class Solution 
{
public:
    void func(TreeNode *root, int v, int d, int depth)
    {
        if(root==NULL)
            return;
        
        if(depth==d-1)
        {
            TreeNode*temp_left=root->left;
            TreeNode*temp_right=root->right;
            TreeNode*new_node1=new TreeNode(v);
            TreeNode*new_node2=new TreeNode(v);
            root->left=new_node1;
            root->right=new_node2;
            new_node1->left=temp_left;
            new_node2->right=temp_right;
        }
        else
        {
            func(root->left,v,d,depth+1);
            func(root->right,v,d,depth+1);
        }
    }

    TreeNode* addOneRow(TreeNode* root, int v, int d) 
    {
        TreeNode*new_node1=new TreeNode(v);
        if(d==1)
        {
            new_node1->left=root;
            return new_node1;
        }
        func(root,v,d,1);
        return root;
    }
};