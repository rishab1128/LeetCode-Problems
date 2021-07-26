class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        map<int,int>mp;
        map<pair<int,int> , int>vis;
        mp[nums[0]]++;
        int ans=0;
        for(int j=1; j<nums.size(); j++)
        {
            int target1=nums[j]+k;
            int target2=nums[j]-k;
            
            if(mp.find(target1)!=mp.end() and vis[{nums[j],target1}]==0){
                ans++;
                vis[{nums[j],target1}]=1;
                vis[{target1,nums[j]}]=1;
            }
                
            if(mp.find(target2)!=mp.end() and vis[{nums[j],target2}]==0){
                ans++;
                vis[{nums[j],target2}]=1;
                vis[{target2,nums[j]}]=1;
            }
            
            mp[nums[j]]=1;
        }
        return ans;
        
    }
};