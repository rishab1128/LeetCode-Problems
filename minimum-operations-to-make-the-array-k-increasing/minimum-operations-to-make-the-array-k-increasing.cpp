class Solution {
public:
    int LIS(vector<int>arr)
    {
        int size=arr.size();
        vector<int>dp(size,1);
        vector<int>seq;
        seq.push_back(arr[0]);
        dp[0]=1;
        for(int i=1; i<size; i++)
        {
            if(seq.back()<=arr[i])
            {
                dp[i]=seq.size()+1;
                seq.push_back(arr[i]);
            }
            else
            {
                int pos=upper_bound(seq.begin(),seq.end(),arr[i])-seq.begin();
                dp[i]=pos+1;
                seq[pos]=arr[i];
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
    
    int kIncreasing(vector<int>& arr, int k)
    {
        int n=arr.size();
        int ans=0;
        
        vector<vector<int>>res;
        int t=0;
        for(int i=0; i<k; i++)
        {
            vector<int>tmp;
            for(int j=t; j<n; j+=k)
                tmp.push_back(arr[j]);
            t++;
            res.push_back(tmp);
        }
        
        for(int i=0; i<k; i++)
        {
            int sz=res[i].size();
            int lis=LIS(res[i]);
            // cout<<sz<<" "<<lis<<endl;
            ans+=sz-lis;
        }
        
        return ans;
    }
};