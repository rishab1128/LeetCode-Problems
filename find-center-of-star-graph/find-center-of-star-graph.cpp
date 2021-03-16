class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        int m=edges.size();
        int ans;
        int deg[m+1];
        memset(deg,0,sizeof(deg));
        for(int i=0; i<m; i++)
        {
            int a=edges[i][0] , b=edges[i][1];
            deg[a-1]++;
            deg[b-1]++;
            if(deg[a-1]>1)
            {
                ans=a;
                break;
            }
            else if(deg[b-1]>1)
            {
                ans=b;
                break;
            }
        }
        return ans;
    }
};