class Solution {
public:
    int search(vector<int>& arr, int target) {
        
        int n  = arr.size();
        int low = 0 , high = n-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(arr[mid]==target)
                return mid;
            
            if(arr[low]<=arr[mid]) //left part is sorted
            {
                if(arr[low]<=target and target<=arr[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
            else //right part is sorted
            {
                if(arr[mid]<=target and target<=arr[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return -1;
        
    }
};