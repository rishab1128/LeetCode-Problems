class Solution 
{
public:
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        if(!root) 
            return root;
        
        queue<TreeNode*> q;
        vector<int> val;
        q.push(root);
        int level=0;
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> temp;
            for(int i=0; i<sz; i++)
            {
                TreeNode* node = q.front(); 
                q.pop();
                
                if(level%2)
                    node->val = val.back() , val.pop_back();
                
                if(node->left)
                {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right) 
                {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
                
            }
            val = temp;
            level++;
        }
        return root;
            
        
    }
};