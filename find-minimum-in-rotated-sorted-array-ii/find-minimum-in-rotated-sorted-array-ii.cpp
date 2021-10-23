class Solution {
public:
    int findMin(vector<int>& arr) 
    {
        int n=arr.size();
        int low=0,high=n-1 , ans=min(arr[0],arr[n-1]);
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]>arr[high])
                low=mid+1;
            else if(arr[mid]<arr[high])
                high=mid;
            else
            {
                if(arr[high - 1] > arr[high]) {
                    low = high;
                    break;
                }
                high--;
            }
                
        }
        return arr[low];
        
    }
};