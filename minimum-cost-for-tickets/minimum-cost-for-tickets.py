import bisect
class Solution:
    
    def func(self,days,costs,idx,dp):
        if(idx>=len(days)):
            return 0
        if(dp[idx]!=0):
            return dp[idx]
        
        pos0=bisect.bisect_right(days, days[idx]+6, 0, len(days))
        pos1=bisect.bisect_right(days, days[idx]+29, 0, len(days))
        
        op1=costs[0]+self.func(days,costs,idx+1,dp)
        op2=costs[1]+self.func(days,costs,pos0,dp)
        op3=costs[2]+self.func(days,costs,pos1,dp)
        
        dp[idx]=min(op1,op2,op3)
        return dp[idx]
        
    
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        self.days, self.costs = days, costs
        dp=[0]*366
        return self.func(days,costs,0,dp)
        