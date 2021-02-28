class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        n=len(items)
        ct=0
        # print("Key = {} and Value = {}".format(ruleKey,ruleValue))
        for i in range(n):
            ele=items[i]
            # print(ele[0])
            if(ruleKey=="type" and ele[0]==ruleValue):
                ct+=1
            elif(ruleKey=="color" and ele[1]==ruleValue):
                ct+=1
            elif(ruleKey=="name" and ele[2]==ruleValue):
                ct+=1
        return ct
                
                
        
        