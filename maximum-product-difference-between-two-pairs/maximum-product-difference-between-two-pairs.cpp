class Solution {
public:
    int maxProductDifference(vector<int>& arr) 
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int p1=arr[0]*arr[1];
        int p2=arr[n-2]*arr[n-1];
        return p2-p1;
    }
};