// struct TreeNode 
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;     
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
// };
​
class Solution 
{
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int depth[101],par[101];
    void dfs(TreeNode*root,TreeNode*parent)
    {
        if(root)
        {
            depth[root->val]=1+depth[parent->val];
            par[root->val]=parent->val;
            dfs(root->left,root);
            dfs(root->right,root);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) 
    {
        memset(depth,0,sizeof(depth));
        memset(par,-1,sizeof(par));
        depth[root->val]=-1;
        dfs(root,root);
        /*for(int i=1; i<=100; i++)
        {
            cout<<i<<" "<<depth[i]<<" "<<par[i]<<endl;
        }*/
        if(depth[x]==depth[y]&&par[x]!=par[y]&&par[x]!=-1&&par[y]!=-1)
            return true;
        
        return false;
    }
};
​
