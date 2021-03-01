class Solution:
    def distributeCandies(self, candy: List[int]) -> int:
        #Using set
        st=set([])  #Explicitly defining a set
        # print(type(st))
        for x in candy:
            st.add(x)
        for x in st:
            print(x)
        n ,m =len(candy) , len(st)
        # print(n, m)
        
        return min(n//2,m)
        
            
        