class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        int n=arr.size() , ans=0;
        int start = bottom;
        for(auto x: arr){
            ans=max(ans,x-start);
            start=x+1;
        }
        ans=max(ans,top-arr[n-1]);
        return ans;
    }
};