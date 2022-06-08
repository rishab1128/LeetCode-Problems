class Solution:
    def check_palin(self, s: str) -> bool:
        t=s[::-1]
        if(t==s):
            return True
        else:
            return False
        
    def removePalindromeSub(self, s: str) -> int:
        if(len(s)==0):
            return 0
        elif(self.check_palin(s)):
            return 1
        else:
            return 2
        