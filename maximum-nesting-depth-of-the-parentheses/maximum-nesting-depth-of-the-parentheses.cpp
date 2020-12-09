#include<bits/stdc++.h>
using namespace std;
​
class Solution {
public:
    int maxDepth(string s) 
    {
        int op=0,ans=0;
        int n=s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
            {
                op++;
                ans=max(ans,op);
            }
            else if(s[i]==')')
                op--;
        }
        return ans;
        
    }
};
