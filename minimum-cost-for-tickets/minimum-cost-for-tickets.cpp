class Solution {
public:
    int dp[366];
    int func(vector<int>& days, vector<int>& costs, int idx)
    {
        // if(idx==days.size()-1)
        //     return costs[0];
        if(idx>=days.size())
            return 0;
        
        if(dp[idx])
            return dp[idx];
        
        int pos0=upper_bound(days.begin(),days.end(),days[idx]+6)-days.begin();
        int pos1=upper_bound(days.begin(),days.end(),days[idx]+29)-days.begin();
        
        int op1=costs[0]+func(days,costs,idx+1);
        int op2=costs[1]+func(days,costs,pos0);
        int op3=costs[2]+func(days,costs,pos1);
        
        return dp[idx]=min({op1,op2,op3});
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        memset(dp,0,sizeof(dp));
        return func(days,costs, 0);
    }
};