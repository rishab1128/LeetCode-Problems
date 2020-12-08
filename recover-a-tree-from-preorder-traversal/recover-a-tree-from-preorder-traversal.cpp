#include<bits/stdc++.h>
using namespace std;
​
// struct TreeNode 
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;     
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
// };
​
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) 
    {
        stack<TreeNode*>st;
        int n=S.size(),i=0;
        while(i<n)
        {
            int level=0;
            int val=0;
            
            while(S[i]=='-')
            {
                i++;
                level++;
            }
            
            for(; i<n&&S[i]!='-'; i++)
            {
                val=val*10+S[i]-'0';
            }
            TreeNode*node=new TreeNode(val);
            while(st.size()>level)st.pop();
            if(!st.empty())
            {
                if(!st.top()->left)
                    st.top()->left=node;
                else if(!st.top()->right)
                    st.top()->right=node;
            }
            st.push(node);
        }
        while(st.size()>1)
            st.pop();
        return st.top();
    }
};
