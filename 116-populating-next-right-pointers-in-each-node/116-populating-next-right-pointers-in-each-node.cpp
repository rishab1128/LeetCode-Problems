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
    
    void recur(Node* &node1 , Node* &node2)
    {
        if(!node1 || !node2)
            return;
        node1->next = node2;
        recur(node1->left,node1->right);
        recur(node1->right,node2->left);
        recur(node2->left,node2->right);
    }
    
    Node* connect(Node* root) 
    {
        if(!root)
            return root;
        
        if(root and !root->left and !root->right)
        {
            root->next = NULL;
            return root;
        }
        
        recur(root->left,root->right);
        
        return root;
        
    }
};