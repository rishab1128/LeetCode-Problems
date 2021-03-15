class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        dp = collections.defaultdict(int)
        mod=10**9+7
        
        arr.sort()
        
        for x in arr:
            dp[x]=1
        for i in range(1,len(arr)):
            for j in range(i):
                x,y,z=arr[i],arr[j],arr[i]//arr[j]
                if(y*z==x):
                    dp[x]+=dp[y]*dp[z]
    
        ans=sum(dp.values())%mod
        return ans
        