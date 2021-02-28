class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        stack=[]
        pos=[]
        n=len(S)
        for i in range(n):
            if(S[i]=='('):
                stack.append(i)
            elif(S[i]==')' and len(stack)>1):
                stack.pop()
            elif(S[i]==')' and len(stack)==1):
                x=stack.pop()
                pos.append([x,i])
        flag=0
        ans=""
        for lst in pos:
            #print("[{} {}]".format(lst[0],lst[1]),end=" ")
            if(lst[1]-lst[0]>1):
                flag=1
                ans+=S[lst[0]+1:lst[1]]
            
        if(not(flag)):
            return ""
        
        return ans
                