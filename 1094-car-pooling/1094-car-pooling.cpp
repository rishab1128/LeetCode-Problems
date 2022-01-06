class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        vector<int>arr(1001,0);
        int n=trips.size();
        for(int i=0; i<n; i++)
        {
            int cap=trips[i][0] , x=trips[i][1] , y=trips[i][2];
            arr[x]+=cap;
            arr[y]-=cap;
        }
        for(int i=1; i<1001; i++)
            arr[i]+=arr[i-1];
        
        int maxi=*max_element(arr.begin(),arr.end());
        
        return maxi<=capacity;
        
    }
};