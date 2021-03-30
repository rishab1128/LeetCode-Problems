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
    int maxLevelSum(TreeNode* root) 
    {
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        vector<int> lvl(10005,0) , vis(10005,0) , child(10005,0);
        int ans=0,level=1;
        
        if(root)
        {
            child[1]=1;
            ans=root->val;
            level=1;
        }
        else
            return 1;
        
        while(q.size()>0)
        {
            auto pair=q.front();
            q.pop();
            
            lvl[pair.second]+=pair.first->val;
            vis[pair.second]++;
            
            if(pair.first->left and pair.first->right)
                child[pair.second+1]+=2;
            else if(pair.first->left or pair.first->right)
                child[pair.second+1]+=1;
            else
                child[pair.second+1]+=0;
            
            if(vis[pair.second]==child[pair.second])
            {
                if(ans<lvl[pair.second])
                {
                    ans=lvl[pair.second];
                    level=pair.second;
                }
            }
            //cout<<ans<<" "<<pair.second<<endl;
            if(pair.first->left)
                q.push({pair.first->left,pair.second+1});
            if(pair.first->right)
                q.push({pair.first->right,pair.second+1});
        }
        return level;
        
    }
};