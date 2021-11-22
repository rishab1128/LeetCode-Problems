class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root)
        {
            //We recursively call the function until we find the target node
            if(key < root->val) 
                root->left = deleteNode(root->left, key);     
            else if(key > root->val) 
                root->right = deleteNode(root->right, key);       
            else
            {
                if(!root->left && !root->right) //No child condition
                    return NULL;          
                if (!root->left || !root->right) //One child contion -> replace the node with it's child
                    return root->left ? root->left : root->right;    
					                                                
                TreeNode* temp = root->left;   //Two child condition                        
                while(temp->right != NULL) temp = temp->right; //Find the largest value in the left subtree of root      
                
                root->val = temp->val;                            
                root->left = deleteNode(root->left, temp->val);  
            }
        }
        
        return root;
    }   
};