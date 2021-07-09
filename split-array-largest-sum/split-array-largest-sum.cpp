class Solution {
public:
    bool check(vector<int>&arr , int&k , int&m, int&flag)
    {
        int n=arr.size() ;
        int i=0 , ct=0 , sum=0;
        while(i<n)
        {
            if(sum+arr[i]>k)
            {
                ct++;
                sum=arr[i];
                if(sum==k)
                    flag=1;
                i++;
            }
            else if(sum+arr[i]==k)
            {
                sum+=arr[i];
                i++;
                flag=1;
            }
            else
            {
                sum+=arr[i];
                if(sum==k)
                    flag=1;
                i++;
            }
        }
        // if(sum==k)
        //     flag=1;
        //cout<<k<<" "<<ct<<" "<<flag<<endl;
        if( ct<m)
            return true;
        return false;
    }
    
    int splitArray(vector<int>& arr, int m) 
    {
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end() ,0);
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int flag=0;
            if(check(arr,mid,m,flag))
            {
                if(flag)
                    ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        
        return ans;
        
        
    }
};