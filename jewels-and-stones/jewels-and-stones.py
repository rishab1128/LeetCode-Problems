class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        mp={}
        for x in jewels:
            mp[x]=1
        ct=0
        # for x,y in mp.items():
        #     print(x, y)
        for x in stones:
            if(x in mp):
                ct+=1
        return ct
            
        