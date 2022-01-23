class Solution {
public:
    int n;
    
    bool isValid(int num, vector<vector<int>>&states)
    {
        for(int i=0; i<n; i++)
        {
            if(num&(1<<i))
            {
                for(int j=0; j<n; j++)
                {
                    bool set1=num&(1<<j);
                    if(states[i][j]!=2 and states[i][j]!=set1)
                        return false;
                }
            }
        }
        return true;
    }
    
    int maximumGood(vector<vector<int>>& states) 
    {
        n=states.size() ;
        int ans=0;
        //Using bitmasking to try out all possible 2^n configurations
        for(int i=0; i<(1<<n); i++)
        {
            if(isValid(i,states))
                ans=max(ans,__builtin_popcount(i));
        }
        return ans;
        
    }
};