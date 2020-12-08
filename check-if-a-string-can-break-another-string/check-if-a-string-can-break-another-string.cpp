#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
class Solution 
{
public:
    Solution(){
        std::ios::sync_with_stdio(false);
    }
​
    bool checkIfCanBreak(string s1, string s2) 
    {
        int n=s1.size();
        sort(all(s1));
        sort(all(s2));
        cout<<s1<<endl<<s2<<endl;
        int i=0;
        while(s1[i]==s2[i]&&i<n)
        {
            i++;
        }
        if(i<n&&s1[i]>s2[i])
        {
            for(int j=i+1; j<n; j++)
            {
                if(s1[j]<s2[j])
                    return false;
            }
        }
        else if(i<n&&s1[i]<s2[i])
        {
            for(int j=i+1; j<n; j++)
            {
                if(s1[j]>s2[j])
                    return false;
            }
        }
        return true;
​
    }
};
