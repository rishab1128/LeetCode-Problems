class Solution {
public:
    int vis[16]={};
    int ct=0;
    
    int recur(int n , int pos)
    {
        if(pos>n)
            return ct++;
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0 and (i%pos==0 || pos%i==0))
            {
                vis[i]=1;
                recur(n,pos+1);
                vis[i]=0;
            }
        }
        return ct;
    }
    int countArrangement(int n) {
        return recur(n,1);    
    }
};