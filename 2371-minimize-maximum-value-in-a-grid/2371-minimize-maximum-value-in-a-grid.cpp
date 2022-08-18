class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& arr) 
    {
        
        int n = arr.size() , m  = arr[0].size();
        auto cmp = [&](pair<int,int>a , pair<int,int>b)
        {
            int i = a.first , j = a.second;
            int x = b.first , y = b.second;
            return arr[i][j] > arr[x][y];
        };
        priority_queue<pair<int,int> , vector<pair<int,int>> , decltype(cmp)> pq(cmp);
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                pq.push({i,j});
        }
        
        vector<int>rowMax(n,0) , colMax(m,0);
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        while(!pq.empty())
        {
            auto [i,j] = pq.top();
            pq.pop();
            ans[i][j] = max(rowMax[i],colMax[j])+1;
            rowMax[i] = colMax[j] = ans[i][j];
        }
        
        return ans;
        
    }
};