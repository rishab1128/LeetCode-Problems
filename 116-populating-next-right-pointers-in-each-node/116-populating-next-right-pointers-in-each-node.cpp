/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(!root)
            return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size() , ct = sz;
            for(int i=0; i<sz; i++)
            {
                auto node = q.front();
                q.pop();
                ct--;
                if(ct)
                    node->next = q.front();
                else
                    node->next = NULL;
                
                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
            }
        }
        return root;
        
    }
};