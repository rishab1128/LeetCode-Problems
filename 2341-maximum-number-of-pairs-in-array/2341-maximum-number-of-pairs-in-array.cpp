class Solution {
public:
    vector<int> numberOfPairs(vector<int>& arr) 
    {
        unordered_map<int,int>mp;
        for(auto x: arr)
            mp[x]++;
        
        int pairs = 0 , leftOver = 0;
        for(auto [ele,freq] : mp)
        {
            pairs += freq/2;
            leftOver +=  freq%2;
        }
        
        return {pairs,leftOver};
        
    }
};