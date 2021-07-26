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
    TreeNode*func(vector<int>&arr, int start , int end)
    {
        if(start>end)
            return NULL;
        int mid=start+(end-start)/2;
        TreeNode*root=new TreeNode(arr[mid]);
        root->left=func(arr,start,mid-1);
        root->right=func(arr,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int> &arr)
    {
        return func(arr,0,arr.size()-1);
    }

};