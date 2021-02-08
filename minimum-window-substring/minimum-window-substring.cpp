#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) 
    {
        if(s.size()==0||t.size()==0)
            return "";
        unordered_map<char,int>mp;
        unordered_map<char,int>window;
        string ans;
        int left=0,right=0,len=INT_MAX;
        int m=s.size(),n=t.size(),counter=0;
        for(auto x: t)
            mp[x]++;
        while(right<m)
        {
            char ch=s[right];
            if(mp.find(ch)!=mp.end())
            {
                window[ch]++;
                if(window[ch]<=mp[ch])
                    counter++;
            }
            if(counter==n)
            {
                //cout<<check++<<"-- MY CT = "<<counter<<endl;
                while(mp.find(s[left])==mp.end()||mp[s[left]]<window[s[left]])
                {
                    window[s[left]]--;
                    left++;
                }
                if(right - left + 1 < len)
                {
                    len = right - left + 1;
                    ans = s.substr(left, len);
                }
            }
            right++;
        }
        return ans;
    }
};