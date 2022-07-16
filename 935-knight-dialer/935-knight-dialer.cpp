using ll = long long;
class Solution {
public:
    ll dp[4][3][5001];
    const int mod = 1e9+7;
    ll dfs(int x, int y, int movesLeft)
    {
        if(x<0 || y<0|| (x==3 and y!=1) || x>=4 || y>=3)
            return 0;
        
        if(movesLeft==1)
            return 1;
        
        if(dp[x][y][movesLeft])
            return dp[x][y][movesLeft];
        
        //down
        ll go1 = dfs(x+2,y-1,movesLeft-1);
        ll go2 = dfs(x+2,y+1,movesLeft-1);
        ll go3 = dfs(x+1,y-2,movesLeft-1);
        ll go4 = dfs(x+1,y+2,movesLeft-1);
        
        //up
        ll go5 = dfs(x-2,y-1,movesLeft-1);
        ll go6 = dfs(x-2,y+1,movesLeft-1);
        ll go7 = dfs(x-1,y-2,movesLeft-1);
        ll go8 = dfs(x-1,y+2,movesLeft-1);
        
        return dp[x][y][movesLeft] = (go1%mod+go2%mod+go3%mod+go4%mod+go5%mod+go6%mod+go7%mod+go8%mod)%mod;
        
    }
    
    int knightDialer(int n) 
    {
        int ans = 0;
        int k=1;
        
        unordered_map<int,pair<int,int>>pos;
        
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                pos[k].first=i;
                pos[k].second=j;
                k++;
            }
        }
        
        pos[0].first = 3 , pos[0].second=1;
        
        ans = dfs(pos[0].first,pos[0].second,n)%mod;
        
        // cout<<ans<<endl;
        
        for(int i=1; i<=9; i++)
        {
            ans = (ans%mod + dfs(pos[i].first,pos[i].second,n)%mod)%mod;   
        }
        return ans;
    }
};