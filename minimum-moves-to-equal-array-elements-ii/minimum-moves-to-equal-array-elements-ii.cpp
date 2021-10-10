class Solution {
public:
    int minMoves2(vector<int>& arr) 
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int req=arr[n/2];
        int ans=0;
        for(auto x: arr)
            ans+=abs(x-req);
        
        return ans;
    }
};