class Solution {
public:
    bool check(vector<int>&arr, int target, int k)
    {
        //Find if there exists a window of size k such that sum of all the elements of that window>=k
        int sum=0 , n=arr.size();
        for(int i=0; i<k; i++)
            sum+=arr[i];
        if(sum>=target)
            return true;
        int j=0;
        for(int i=k; i<n; i++)
        {
            sum-=arr[j];
            sum+=arr[i];
            if(sum>=target)
                return true;
            j++;
        }
        cout<<k<<" "<<"sum = "<<sum<<endl;
        if(sum>=target)
            return true;
        
        return false;
    }
    
    int minSubArrayLen(int target, vector<int>& nums)
    {
        //BS on answer  as ans lies b/w 0 to nums.size()
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum<target)
            return 0;
        int low=1, high=nums.size();
        int ans=nums.size();
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(nums,target,mid))
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
                low=mid+1;
            cout<<high<<" "<<low<<" "<<mid<<endl;
        }
        return ans;
    }
};