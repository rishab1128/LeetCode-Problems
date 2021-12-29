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
        
        map<int,vector<Node*>>lvl;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                Node*ele=q.front().first;
                int level=q.front().second;
                q.pop();
                lvl[level].push_back(ele);
                if(ele->left)
                    q.push({ele->left,level+1});
                if(ele->right)
                    q.push({ele->right,level+1});
            }
        }
        for(auto ele : lvl)
        {
            vector<Node*>arr=ele.second;
            arr.push_back(NULL);
            int n=arr.size();
            for(int i=0; i<n-1; i++)
                arr[i]->next=arr[i+1];
        }
        return root;
    }
};