class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& qus) 
    {
        int  n=points.size() , m=qus.size();
        
        vector<pair<int,int>>pts;
        vector<int>x_cord;
        vector<int>ans(m,0);
        
        for(int i=0; i<n; i++)
        {
            pts.push_back({points[i][0],points[i][1]});
            x_cord.push_back(points[i][0]);
        }
        sort(pts.begin(),pts.end());
        sort(x_cord.begin() , x_cord.end());
        
        for(int i=0; i<m; i++)
        {
            int x=qus[i][0] , y=qus[i][1] , r=qus[i][2];
            int pos1=lower_bound(x_cord.begin() , x_cord.end() , x-r) - x_cord.begin();
            int pos2=upper_bound(x_cord.begin() , x_cord.end() , x+r) - x_cord.begin()-1;
            
            if(pos1>=0 and pos2>=0 and pos2<n and pos1<=pos2)
            {
                for(int j=pos1; j<=pos2; j++)
                {
                    int xj=pts[j].first, yj=pts[j].second;
                    int X=(x-xj)*(x-xj);
                    int Y=(y-yj)*(y-yj);
                    if(X+Y<=r*r)
                        ans[i]++;
                }
            }
        }
        
        return ans;
        
    }
};