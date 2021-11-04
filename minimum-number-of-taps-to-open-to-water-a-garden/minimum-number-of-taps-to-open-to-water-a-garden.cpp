class Solution {
public:
    //Converting to Jump Game 2 Ques
    int minTaps(int n, vector<int>& ranges)
    {
        vector<int>jump(n+1,0);
        for(int i=0; i<n+1; i++)
        {
            int left=max(0,i-ranges[i]);
            int right=min(n , i+ranges[i]);
            jump[left]=max(jump[left] , right-left);
        }
        
        //Jump Game-II Code
        int currEnd=0,currFarthest=0,jumps=0;
        for(int i=0; i<n; i++)
        {
            currFarthest=max(currFarthest , i+jump[i]);
            if(i==currEnd)
            {
                jumps++;
                currEnd=currFarthest;
            }
        }
        
        if(currEnd>=n)
            return jumps;
        
        return -1;
        
    }
};