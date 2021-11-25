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
    bool isCompleteTree(TreeNode* root) 
    {
        map<int,vector<TreeNode*>>level;
        queue< pair< TreeNode* , int> > q;
        q.push({root,0});
        int depth=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                TreeNode*node=q.front().first;
                int lvl=q.front().second;
                depth=max(depth,lvl);
                q.pop();
                level[lvl].push_back(node);
                if(node->left)
                    q.push({node->left,lvl+1});
                if(node->right)
                    q.push({node->right,lvl+1});
            }
        }
        
        cout<<depth<<endl;
        if(depth==0)
            return true;
        
        for(auto ele : level)
        {
            int lvl=ele.first;
            auto v=ele.second;
            int n=v.size();
            if(lvl!=depth)
            {
                if(n!=(1<<lvl))
                    return false;
            }
            else
            {
                auto par=level[lvl-1];
                int m=par.size();
                int i=0,j=0;
                while(i<n and j<m)
                {
                    if(v[i]==par[j]->left and i%2==0)
                        i++;
                    else if(v[i]==par[j]->right and i%2==1)
                        i++,j++;
                    else
                        return false;
                }
            }
        }
        
        return true;
        
    }
};