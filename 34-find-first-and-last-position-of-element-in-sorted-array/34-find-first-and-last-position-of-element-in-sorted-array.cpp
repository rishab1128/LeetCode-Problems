class Solution {
public:
    
    int upperBound(vector<int>&arr, int target)
    {
        int low = 0 , high = arr.size()-1 , pos=arr.size();
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(arr[mid]>target){
                pos = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return pos;
    }
    
    vector<int> searchRange(vector<int>& arr, int target) 
    {
        if(arr.size()==0)
            return {-1,-1};
        int pos1 = upperBound(arr,target-1);
        if(pos1==arr.size() || (arr[pos1]!=target))
            return {-1,-1};
        
        int pos2 = upperBound(arr,target)-1;
        return {pos1,pos2};
        
    }
};