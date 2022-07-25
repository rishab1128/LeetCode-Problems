class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        using ll = long long;
        int n=nums.size() ;
        set<vector<int>>st;
        map<long long,int>mp;
        sort(nums.begin() , nums.end() );
        for(int i=0; i<n; i++)
            mp[nums[i]]=i;
        // for(auto x: nums)
        //     cout<<x<<" ";
        // cout<<endl;
        
        for(int i=0; i<n; i++)
        {
            //cout<<nums[i]<<endl;
            for(int j=i+1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    long long tot = (ll)nums[i]+(ll)nums[j]+(ll)nums[k];
                    long long search=target-tot;
                    //cout<<nums[i]<<" "<<search<<endl;
                    if(mp.find(search)!=mp.end() and mp[search]>k)
                    {
                        st.insert({nums[i],nums[j],nums[k],(int)search});
                    }
                        
                }
            }
        }
        
        vector<vector<int>>ans;
        for(auto x: st)
            ans.push_back(x);
        
        return ans;
    }
};