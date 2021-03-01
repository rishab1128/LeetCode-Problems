class Solution:
    def distributeCandies(self, candy: List[int]) -> int:
        mp={}
        # print(type(map1))
        for x in candy:
            mp[x]=1
        n ,m =len(candy) , len(mp)
        # print(n, m)
        
        return min(n//2,m)
        
            
        