class Solution {
public:
    int maximumSum(vector<int>& arr) 
    {
        unordered_map<int,int>mp;
        int n = arr.size();
        int ans = -1;
        for(int j=0; j<n; j++)
        {
            int x = arr[j] , sum = 0;
            while(x>0)
            {
                int rem = x%10;
                sum += rem;
                x/=10;
            }
            
            if(mp.count(sum))
                ans = max(ans,mp[sum]+arr[j]);
            
            mp[sum] = max(mp[sum] , arr[j]);
        }
        
        return ans;
        
    }
};