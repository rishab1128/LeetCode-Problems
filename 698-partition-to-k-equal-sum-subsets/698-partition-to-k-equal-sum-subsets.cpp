class Solution {
public:
    
    int dp[(1<<16)+1];
    int k , target;
    
    int recur(int sum, int cnt, int mask, vector<int>&arr)
    {
        if(cnt==k-1)
            return 1;
        
        if(dp[mask]!=-1)
            return dp[mask];
        
        int ans = 0;
        for(int i=0; i<arr.size(); i++)
        {
            if(mask&(1<<i)) //ith index is already taken
                continue;
            
            if(sum+arr[i]>target)
                break;
            if(sum+arr[i]==target)
            {
                mask^=(1<<i); //Set ith bit
                ans=max(ans,recur(0,cnt+1,mask,arr));
                mask^=(1<<i); //Unset ith bit
            }
            else
            {
                mask^=(1<<i); //Set ith bit
                ans=max(ans,recur(sum+arr[i],cnt,mask,arr));
                mask^=(1<<i); //Unset ith bit
            }   
            if(ans==1)
                break;
        }
        return dp[mask]=ans;
    }
    
    bool canPartitionKSubsets(vector<int>& arr, int k) 
    {
        memset(dp,-1,sizeof(dp));
        this->k=k;
        
        int sum  = accumulate(arr.begin(),arr.end(),0);
        
        if(sum%k)
            return false;
        
        target = sum/k;
        // sort(arr.begin(),arr.end());
        return recur(0,0,0,arr);
    }
};