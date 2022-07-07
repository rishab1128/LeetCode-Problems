class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& inter) 
    {
        vector<int>mp(1e6+1,0);
        
        for(auto v: inter)
        {
            int start = v[0] , end = v[1];
            mp[start]++;
            mp[end]--;
        }
        
        for(int i=1; i<mp.size(); i++)
            mp[i] += mp[i-1];
        
        int ans = *max_element(mp.begin(),mp.end());
        return ans;
    }
};