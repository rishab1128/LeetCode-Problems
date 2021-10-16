class Solution {
public:
    int numSplits(string s) 
    {
        int n=s.size();
        vector<int>pref(n) , suff(n);
        map<char,int>mp1,mp2;
        for(int i=0; i<n; i++)
        {
            if(mp1.find(s[i])==mp1.end())
                mp1[s[i]]++;
            pref[i]=mp1.size();
        }
        for(int i=n-1; i>=0; i--)
        {
            if(mp2.find(s[i])==mp2.end())
                mp2[s[i]]++;
            suff[i]=mp2.size();
        }
        int ct=0;
        // for(auto x: pref)
        //     cout<<x<<" ";
        // cout<<endl;
        // for(auto x: suff)
        //     cout<<x<<" ";
        // cout<<endl;
        for(int i=0; i<n-1; i++)
        {
            if(pref[i]==suff[i+1])
                ct++;
        }
        return ct;
        
    }
};