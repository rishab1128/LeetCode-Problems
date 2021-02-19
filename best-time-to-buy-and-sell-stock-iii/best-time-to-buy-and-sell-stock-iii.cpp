class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int left[n],right[n];
        
        left[0]=0;
        int Lt_min=prices[0];
        for(int i=1; i<n; i++)
        {
            Lt_min=min(Lt_min,prices[i]);
            left[i]=max(left[i-1],prices[i]-Lt_min);
        }
        
        right[n-1]=0;
        int Rt_max=prices[n-1];
        for(int i=n-2; i>=0; i--)
        {
            Rt_max=max(Rt_max,prices[i]);
            right[i]=max(right[i+1],Rt_max-prices[i]);
        }
        
        int ans=0;
        for(int i=0; i<n-1; i++)
        {
            ans=max(ans,left[i]+right[i+1]);
        }
        ans=max(ans,left[n-1]);
        return ans;
        
    }
};