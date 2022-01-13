class Solution {
    
    static bool cmp(const vector<int>&a , const vector<int>&b)
    {
        return a[1]<b[1];
    }
    
public:
    int findMinArrowShots(vector<vector<int>>& pts) 
    {
        sort(pts.begin(),pts.end(),cmp);
        int ct=1 , right=pts[0][1];
        for(int i=1; i<pts.size(); i++)
        {
            if(pts[i][0]<=right)
                continue;
            else
            {
                ct++;
                right=pts[i][1];
            }
        }
        return ct;
    }
};