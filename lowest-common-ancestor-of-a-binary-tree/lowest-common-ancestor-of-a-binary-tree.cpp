/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool func(TreeNode*root,TreeNode*a, vector<TreeNode*>&li)
    {
        if(root->val==a->val)
        {
            return true;
        }
        li.push_back(root);
        if(root->left)
            if(func(root->left,a,li))
                return true;
        if(root->right)
            if(func(root->right,a,li))
                return true;
        li.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) 
    {
        TreeNode*ans=root;
        vector<TreeNode*>li1,li2;
        func(root,a,li1);
        func(root,b,li2);
        li1.push_back(a);
        li2.push_back(b);
        cout<<li1.size()<<endl;
        cout<<li2.size()<<endl;
        for(auto x: li1)
            cout<<x->val<<" ";
        cout<<endl;
        for(auto x: li2)
            cout<<x->val<<" ";
        if(li1.size()>li2.size())
            swap(li1,li2);
        int n=li1.size() ;
        for(int i=n-1; i>=0; i--)
        {
            if(li1[i]==li2[i])
            {
                ans=li1[i];
                break;
            }
        }
        return ans;

    }
};