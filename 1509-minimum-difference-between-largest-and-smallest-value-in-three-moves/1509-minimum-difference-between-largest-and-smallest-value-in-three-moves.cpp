class Solution {
public:
    int minDifference(vector<int>& arr) 
    {
        int n = arr.size();
        if(n<=4)
            return 0;
        sort(arr.begin(),arr.end());
        
        int left = 2 , right = n, diff = INT_MAX;
        while(left+1>=0)
        {
            diff = min(diff,arr[right-1]-arr[left+1]);
            left--;
            right--;
        }
        return diff;
        
    }
};