class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        //Refer the first comment in : https://leetcode.com/problems/gas-station/discuss/42568/Share-some-of-my-ideas.
        int n=gas.size() , tot=0;
        for(int i=0; i<n; i++)
            tot+=gas[i]-cost[i];
        
        if(tot<0)
            return -1;
        
        int tank=0,start=0;
        //This is much like Kadane's Algo
        for(int i=0; i<n; i++)
        {
            tank+=gas[i]-cost[i];
            if(tank<0)
            {
                tank=0;
                start=i+1;
            }
        }
        return start;
        
    }
};