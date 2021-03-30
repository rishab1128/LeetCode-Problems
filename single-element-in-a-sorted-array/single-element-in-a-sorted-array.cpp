class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) 
    {
        int n=arr.size();
        int low=0,high=n-1,ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(mid!=0 and arr[mid]==arr[mid-1])
            {
                if((high-mid)%2==0)
                    high=mid-2;
                else
                    low=mid+1;
                //high=mid-1;
            }
            else if(mid!=n-1 and arr[mid]==arr[mid+1])
            {
                if((mid-low)%2==0)
                    low=mid+2;
                else
                    high=mid-1;
                //low=mid;
            }
            else
            {
                ans=arr[mid];
                break;
            }
        }
        return ans;
        
    }
};