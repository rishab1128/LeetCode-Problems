class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) 
    {
        //Refer Note
        set<int> x , y;
        const int mod = 1e9+7;
        
        for(auto rect : rectangles)
        {
            int x1 = rect[0] , x2 = rect[2];
            int y1 = rect[1] , y2 = rect[3];
            
            x.insert(x1);
            x.insert(x2);
            y.insert(y1);
            y.insert(y2);
        }
        
        vector<int> x_coord(x.begin(),x.end());
        vector<int> y_coord(y.begin(),y.end());
        
        unordered_map<int,int> mp1  , mp2;
        
        for(int i=0; i<x_coord.size(); i++)
            mp1[x_coord[i]]=i;
        
        for(int i=0; i<y_coord.size(); i++)
            mp2[y_coord[i]]=i;
        
        
        long long ans = 0;
        int n  =x_coord.size() , m = y_coord.size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        
        for(auto rect :  rectangles)
        {
            int x1 = rect[0] , x2 = rect[2];
            int y1 = rect[1] , y2 = rect[3];
            
            for(int j=mp1[x1]; j<=mp1[x2]-1; j++)
            {
                for(int k=mp2[y1]; k<=mp2[y2]-1; k++)
                {
                    if(vis[j][k])
                        continue;
                    long long width = x_coord[j+1]-x_coord[j];
                    long long height = y_coord[k+1]-y_coord[k];
                    long long area = (width%mod*height%mod)%mod;
                    ans = (ans%mod + area%mod)%mod;
                    vis[j][k]=1;
                }
            }
        }
        
        return ans;
        
    }
};