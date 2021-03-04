class DisjointSet:
    def __init__(self,n):
        self.rank=[0]*n
        self.parent=[0]*n
        self.n=n
        self.makeSet()

    def makeSet(self):
        for i in range(self.n):
            self.parent[i]=i

    def find(self,x) -> int:
        if(self.parent[x]==x):
            return x
        self.parent[x]=self.find(self.parent[x])
        return self.parent[x]

    def Union(self,x,y):
        xset=self.find(x)
        yset=self.find(y)
        if(xset==yset):
            return
        if(self.rank[xset]<self.rank[yset]):
            self.parent[xset]=yset

        elif(self.rank[xset]>self.rank[yset]):
            self.parent[yset]=xset
        else:
            self.parent[yset]=xset
            self.rank[xset]+=1

class Solution:
    def findCircleNum(self, arr: List[List[int]]) -> int:
        n , ct =len(arr) , 0
        obj=DisjointSet(n)
        mp={}
        for i in range(n):
            for j in range(n):
                if(i!=j and arr[i][j]==1 and obj.find(i)!=obj.find(j)):
                    obj.Union(i,j)
    
        for i in range(n):
            if(obj.find(i) not in mp):
                ct+=1
                mp[obj.find(i)]=1

        return ct   
        