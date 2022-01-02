class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        unordered_map<int,int>mp;
        for(int i=0; i<time.size(); i++)
            time[i]=time[i]%60;
        
        int ct=0;
        for(int i=0; i<time.size(); i++)
        {
            int search=(60-time[i])%60;
            if(mp.find(search)!=mp.end())
                ct+=mp[search];
            mp[time[i]]++;
        }
        
        return ct;
        
    }
};