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
    void help(Node*curr , Node*next)
    {
        if(!curr)
            return;
        curr->next=next;
        help(curr->left,curr->right);
        help(curr->right, curr->next==NULL ? NULL : curr->next->left);
    }
    
    Node* connect(Node* root)
    {
        if(!root)
            return root;
        help(root,NULL);
        return root;
    }
};