class Solution {
public:
    int maxOperations(vector<int>& arr, int k) 
    {
        unordered_map<int,int>mp , vis;
        for(auto x: arr)
            mp[x]++;
        int ans=0;
        for(auto [ele , freq] :  mp){
            int target = k-ele;
            if(target!=ele && mp.count(target) && !vis[ele])
            {
                ans+=min(mp[target],freq);
                vis[target]=1;
            }
            else if(target==ele)
                ans+=freq/2;
        }
        return ans;
    }
};