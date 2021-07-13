class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) 
    {
        int n=arr.size();
        if(n==0)
            return {-1,-1};
        int first=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
        
        if(first==n || arr[first]!=target)
            return {-1,-1};
        
        int last=upper_bound(arr.begin(),arr.end(),target)-arr.begin();
        
        return {first,last-1};
        
    }
};