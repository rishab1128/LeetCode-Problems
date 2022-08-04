class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) 
    {
        int n = arr.size();
        int low = 0 , high = n-1;
        while(low<high)
        {
            int mid = low+(high-low)/2;
            if(mid+1<n and arr[mid]==arr[mid+1])
            {
                int len = (n-1)-(mid+1);
                if(len%2==0)
                    high = mid-1;
                else
                    low = mid+2;
            }
            else if(mid+1<n and arr[mid]!=arr[mid+1])
            {
                int len = (n-1)-mid;
                if(len%2==0)
                    high = mid;
                else
                    low = mid+1;
            }
        }
        return arr[low];
        
    }
};