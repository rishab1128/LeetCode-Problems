class Solution {
public:
    
    int firstPos(vector<int>&arr, int target)
    {
        int low = 0 , high = arr.size()-1 , pos = -1;
        while(low<=high)
        {
            int mid = (low+high)>>1;
            if(arr[mid]>=target)
            {
                if(arr[mid]==target)
                    pos = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return pos;
    }
    int lastPos(vector<int>&arr, int target)
    {
        int low = 0 , high = arr.size()-1 , pos = -1;
        while(low<=high)
        {
            int mid = (low+high)>>1;
            // cout<<mid<<" "<<arr[mid]<<" "<<pos<<endl;
            if(arr[mid]<=target)
            {
                if(arr[mid]==target)
                    pos = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return pos;
    }
    
    vector<int> searchRange(vector<int>& arr, int target) 
    {
        int pos1 = firstPos(arr,target);
        if(pos1==-1)
            return {-1,-1};
        
        int pos2 = lastPos(arr,target);
        return {pos1,pos2};
        
    }
};