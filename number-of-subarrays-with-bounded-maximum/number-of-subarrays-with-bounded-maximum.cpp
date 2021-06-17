class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) 
    {
        int n=nums.size() , ans=0;
        int vis[n];
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++)
        {
            if(nums[i]>=left and nums[i]<=right)
            {
                vis[i]=1;
                int a=i-1, b=i+1, lt=0, rt=0;
                while(a>=0 and nums[a]<=nums[i])
                {
                    if(vis[a] and nums[a]==nums[i])
                        break;
                    a--;
                    lt++;
                }
                while(b<n and nums[b]<=nums[i])
                {
                    b++;
                    rt++;
                }
                   
                
                ans+=(lt+rt+lt*rt+1);
                cout<<i<<" "<<ans<<endl;
            }
        }
        return  ans;
        
    }
};