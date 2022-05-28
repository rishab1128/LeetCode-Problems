class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n=len(nums)
        sum1=sum(nums)
        t_sum=n*(n+1)//2
        miss=t_sum-sum1
        return miss
        