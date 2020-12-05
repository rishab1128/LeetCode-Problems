#include<bits/stdc++.h>
using namespace std;
​
class Solution {
public:
    int titleToNumber(string s) 
    {
        reverse(s.begin(),s.end());
        int n=s.size(),ans=0;
        for(int i=0; i<n; i++)
        {
            ans+=(pow(26,i)*(s[i]-65+1));
        }
        return ans;
        
    }
};
