class Solution {
public:
    int rearrangeCharacters(string s, string target) 
    {
        unordered_map<char,int>mp1,mp2;
        for(auto x: s)
            mp1[x]++;
        for(auto x: target)
            mp2[x]++;
        
        int ans = INT_MAX;
        for(auto x: mp2)
        {
            char ch = x.first;
            int f1 = mp1[ch] , f2 = mp2[ch];
            int can = f1/f2;
            // cout<<ch<<" "<<f1<<" "<<f2<<" "<<can<<endl;
            ans = min(ans,can);
        }
        
        return ans;
        
    }
};