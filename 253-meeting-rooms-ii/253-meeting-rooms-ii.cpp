class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& inter) 
    {
        map<int,int>mp;
        
        for(auto v: inter)
        {
            int start = v[0] , end = v[1];
            mp[start]++;
            mp[end]--;
        }
        
        int ans = 0 , last = 0;
        for(auto &[ele,freq] : mp)
        {
            freq += last;
            ans = max(ans,freq);
            last = freq;
        }
        
        
        return ans;
    }
};