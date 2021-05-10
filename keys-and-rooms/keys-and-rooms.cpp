class Solution {
public:
    int vis[1001];
    void dfs(vector<vector<int>>& rooms , int idx)
    {
        vis[idx]=1;
        for(int i=0; i<(int)rooms[idx].size(); i++)
        {
            int room_no=rooms[idx][i];
            if(vis[room_no]==0)
                dfs(rooms,room_no);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n=rooms.size();
        memset(vis,0,sizeof(vis));
        dfs(rooms,0);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
                return false;
        }
        return true;
        
    }
};