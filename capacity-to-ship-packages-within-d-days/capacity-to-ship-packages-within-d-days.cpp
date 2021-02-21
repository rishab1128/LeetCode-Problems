class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    
    bool check(int mid, vector<int>&arr, int d)
    {
        int sum=0,i=0,ct=0;
        while(i<(int)arr.size())
        {
            if(arr[i]>mid)
                return false;
            if(sum+arr[i]<=mid)
                sum+=arr[i];
            else
            {
                ct++;
                sum=arr[i];
            }
            i++;
        }
        //cout<<mid<<" "<<ct+1<<endl;
        if(ct+1>d)
            return false;
        return true;
        
    }
    
    int shipWithinDays(vector<int>& weights, int D) 
    {
        int sum=0,ans=0;
        for(auto x: weights)
            sum+=x;
        int low=1,high=sum;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(mid,weights,D))
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