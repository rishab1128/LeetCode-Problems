class Solution {
public:
    bool check(int k , vector<int>&arr , int r , int b)
    {
        //Window Size = r
        //No. of non-overlapping windows = b
        int n=arr.size();
        int windows=0 ,left=0, right=0;
        while(right<n)
        {
            if(arr[right]>k)
            {
                right++;
                left=right;
            }
            else
            {
                if(right-left+1==r)
                {
                    windows++;
                    right++;
                    left=right;
                }
                else
                    right++;
            }
        }

        //cout<<k<<" "<<windows<<endl;

        if(windows>=b)
            return true;

        return false;
    }

    int minDays(vector<int>& arr, int m, int k) 
    {
        int n=arr.size();
        if(k*m>n)
            return -1;
        int low=1,high=*max_element(arr.begin(),arr.end()),ans=1;
        //check(12,arr,r,b);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(mid,arr,k,m))
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