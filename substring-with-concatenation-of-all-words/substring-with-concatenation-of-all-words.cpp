#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        unordered_map<string,int>map;
        vector<int>ans;
        for(auto x: words)
            map[x]++;
        int sz=words[0].size();
        int n=s.size(),m=words.size();
        if(n==0||m==0)
            return ans;
        for(int i=0; i<n-sz*m+1; i++)
        {
            unordered_map<string,int>seen;
            int j=0;
            for(; j<m; j++)
            {
                string tmp=s.substr(i+j*sz,sz);
                if(map.count(tmp))
                {
                    seen[tmp]++;
                    if(seen[tmp]>map[tmp])
                        break;
                }
                else
                    break;
            }
            if(j==m)
                ans.push_back(i);
        }
        return ans;
    }
};