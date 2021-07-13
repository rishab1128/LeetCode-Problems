/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int height(Node*root)
    {
        if(!root)
            return 0;
        int ht=0;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(q.size() > 0)
        {
            Node*node=q.front().first;
            int lvl=q.front().second;
            q.pop();
            if(node->children.size() > 0)
            {
                for(auto x: node->children)
                    q.push({x,lvl+1});
                ht=lvl+1;
            }
        }
        return ht+1; 
    }
    
    vector<vector<int>> levelOrder(Node* root) 
    {
        queue<pair<Node*,int>>q;
        int h=height(root);
        if(h==0)
            return {};
        
        //cout<<h<<endl;
        
        vector<vector<int>>ans(h);
        q.push({root,0});
        while(!q.empty())
        {
            Node*node=q.front().first;
            int lvl=q.front().second;
            ans[lvl].push_back(node->val);
            q.pop();
            for(auto x: node->children)
                q.push({x,lvl+1});
        }
        
        return ans;
    }
};