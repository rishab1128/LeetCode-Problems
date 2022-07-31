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

//SC : O(H) , H = height of the BST
//TC : O(1)
    
class BSTIterator {
private:stack<TreeNode*>st;
        void pushIntoStack(TreeNode*root)
        {
            while(root)
            {
                st.push(root);
                root = root->left;
            }
        }
        
public:
    
    BSTIterator(TreeNode* root) 
    {
        pushIntoStack(root);
    }
    
    int next() 
    {
        TreeNode*node = st.top();
        int ans = node->val;
        st.pop();
        
        if(node->right)
        {
            node = node->right;
            pushIntoStack(node);
        }
        
        return ans;
    }
    
    bool hasNext() {
        return st.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */