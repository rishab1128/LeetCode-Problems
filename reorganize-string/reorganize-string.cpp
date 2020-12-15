​
    string reorganizeString(string S) 
    {
        map<char,int>mp;
        char ch;
        if(!check(S,mp,ch))
            return "";
        int n=S.size();
        string ans(n,'0');
        int idx=0;
        while(mp[ch]>0)
        {
            ans[idx]=ch;
            mp[ch]--;
            idx+=2;
        }
        // for(auto x: mp)
        //     cout<<x.first<<" "<<x.second<<endl;
        for(auto x: mp)
        {
            
            while(mp[x.FF]>0)
            {
                if(idx>=n)
                    idx=1;
                ans[idx]=x.FF;
                mp[x.FF]--;
                idx+=2;
            }
        }
        return ans;
​
    }
};
​
