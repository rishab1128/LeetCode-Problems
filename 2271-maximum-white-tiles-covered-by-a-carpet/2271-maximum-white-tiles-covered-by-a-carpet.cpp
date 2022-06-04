class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int len) 
    {
        int n = tiles.size();
        int start=0,end=0,full=0,partial=0,ans=0;
        sort(tiles.begin(),tiles.end());
        while(end<n and ans<len)
        {
            if(tiles[start][0]+len>tiles[end][1])
            {
                full+=tiles[end][1]-tiles[end][0]+1;
                ans=max(ans,full);
                end++;
            }
            else
            {
                partial=max(0,tiles[start][0]+len-tiles[end][0]);
                ans=max(ans,full+partial);
                full-=(tiles[start][1]-tiles[start][0]+1);
                start++;
            }
        }
        return ans;
        
    }
};