class Solution {
public:
    bool check(vector<int>&arr, int&mid, int&maxi)
    {
        int res=0;
        for(auto x: arr)
        {
            double tmp=((double)x)/mid;
            res+=ceil(tmp);
        }
        return res<=maxi;
        
    }
    
    int smallestDivisor(vector<int>& arr, int maxi) 
    {
        int low=1 , high=*max_element(arr.begin(),arr.end());
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(arr,mid,maxi))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};