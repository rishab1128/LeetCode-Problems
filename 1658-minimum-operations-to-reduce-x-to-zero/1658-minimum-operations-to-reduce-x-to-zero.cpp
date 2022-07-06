class Solution {
public:
    int minOperations(vector<int>& arr, int x) 
    {
        int n = arr.size();
        int left = 0 , right = n-1, ops=0, sum=0 , ans=INT_MAX;
        while(left<n and sum<x)
        {
            sum+=arr[left];
            left++;
            ops++;
        }
        if(sum==x)
            ans = ops;
        
        if(sum<x and left==n)
            return -1;
        
        left--;
        
        
        while(right>=0)
        {
            sum+=arr[right];
            ops++;
            while(left>=0 and sum>x)
            {
                sum-=arr[left];
                left--;
                ops--;
            }
            // cout<<sum<<" "<<left<<" "<<ops<<endl;
            if(sum==x)
                ans=min(ans,ops);
            right--;
        }
        
        return ans==INT_MAX ? -1 : ans;
    }
};