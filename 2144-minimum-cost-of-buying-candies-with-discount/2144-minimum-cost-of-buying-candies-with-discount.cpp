class Solution {
public:
    int minimumCost(vector<int>& cost) 
    {
        sort(begin(cost),end(cost));
        int n=size(cost),ans=0;
        for(int i=n-1; i>=0; i-=3)
            ans+=i-1>=0 ? cost[i]+cost[i-1] : cost[i];
        return ans;
        
    }
};