class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) 
    {
        int n = rectangles.size();
        
        sort(rectangles.begin(),rectangles.end());
        
        vector<int>width;
        vector<vector<int>>ht(101);
        
        for(int i=0 ; i<n; i++)
        {
            int w = rectangles[i][0] , h = rectangles[i][1];
            width.push_back(w);
            ht[h].push_back(i);
        }
        
        // for(auto v: rectangles)
        //     cout<<v[0]<<" "<<v[1]<<endl;
            
        vector<int>res;
        for(auto point :  points)
        {
            int x  = point[0] , y = point[1] , ans=0;
            int idx = lower_bound(width.begin() , width.end() , x) - width.begin();
            if(idx==n){
                res.push_back(0);
                continue;
            }
                
            
            for(int j=y; j<=100; j++)
            {
                int m = ht[j].size();
                int idx2 = lower_bound(ht[j].begin(),ht[j].end(),idx)-ht[j].begin();
                ans+=m-idx2;
            }
            res.push_back(ans);
        }
        
        return res;
        
        
    }
};