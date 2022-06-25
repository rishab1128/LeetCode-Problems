class Solution {
public:
    
    static bool cmp(const vector<int>&a, const vector<int>&b)
    {
        return a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& arr) 
    {
        int n = arr.size();
        sort(arr.begin(),arr.end(),cmp);    
        int last = arr[0][1] , cnt = 0;
        for(int i=1; i<n; i++)
        {
            if(arr[i][0]<last)
                cnt++;
            else
                last = arr[i][1];
        }
        return cnt;
        
    }
};