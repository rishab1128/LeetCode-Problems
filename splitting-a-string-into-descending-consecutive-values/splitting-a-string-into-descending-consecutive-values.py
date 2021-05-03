class Solution:
    def splitString(self, s: str) -> bool:
        
        def dfs(index , prev_val):
            if(index==len(s)):
                return True
            
            for j in range(index,len(s)):
                val=int(s[index:j+1])
                if(val+1==prev_val and dfs(j+1 , val)):
                    return True
            
            return False
            
        for i in range(len(s)-1):
            val=int(s[0:i+1]) #s[i:j+1] --> substring from idx i to j
            if(dfs(i+1 , val)):
                return True
            
        return False