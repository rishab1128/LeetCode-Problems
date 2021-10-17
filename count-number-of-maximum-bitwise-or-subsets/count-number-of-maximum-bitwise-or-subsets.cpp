class Solution {
public:
    int generate(vector<int>&arr)
    {
        int n=arr.size();
        int sz=(1<<n)-1;
        vector<vector<int>>ans;
        for(int i=0; i<=sz; i++)
        {
            vector<int>subset;
            for(int j=0; j<n; j++)
            {
                if(i&(1<<j))
                    subset.push_back(arr[j]);
            }
            ans.push_back(subset);
        }
        map<int,int>mp;
        int maxi=INT_MIN;
        for(int i=0; i<ans.size(); i++)
        {
            int tot=0;
            for(auto x: ans[i])
                tot|=x;
            mp[tot]++;
            maxi=max(maxi,tot);
        }
        
        return mp[maxi];
    }
    
    int countMaxOrSubsets(vector<int>& nums) 
    {
        return generate(nums);
    }
};