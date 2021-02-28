class Solution:
    def maximumWealth(self, acc: List[List[int]]) -> int:
        n=len(acc)
        ans=0
        for i in range(n):
            ans=max(ans,sum(acc[i]))
        return ans