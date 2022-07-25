class Solution {
public:
    //O(N) solution
    int jump(vector<int>& arr) 
    {
        int n  =arr.size();
        int currEnd = 0 , currFarthest = 0 , jumps = 0;
        for(int i=0; i<n; i++)
        {
            if(i>currEnd)
                return -1;
            
            if(i==n-1)
                return jumps;
            currFarthest = max(currFarthest , i+arr[i]);
            if(i==currEnd)
            {
                jumps++;
                currEnd = currFarthest;
            }
            
        }
        return jumps;
    }
};