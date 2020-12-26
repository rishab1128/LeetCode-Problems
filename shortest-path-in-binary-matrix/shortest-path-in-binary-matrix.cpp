#include<bits/stdc++.h>
using namespace std;
​
class Solution 
{
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
​
    int bfs(vector<vector<int>>& grid, int n)
    {
        vector<pair<int,int>>directions={{1,1},{0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        queue<pair<int,int>>q;
        q.push(make_pair(0,0));
        grid[0][0]=1;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==n-1&&y==n-1) 
                return grid[x][y];
            for(auto dir: directions)
            {
                int dx=x+dir.first;
                int dy=y+dir.second;
                if(dx<n&&dx>=0&&dy<n&&dy>=0&&grid[dx][dy]==0)
                {
