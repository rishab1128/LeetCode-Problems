class Solution {
public:
    
    static bool cmp(const pair<int,int>&a, const pair<int,int>&b)
    {
        double t1 = ((double)a.first)/a.second;
        double t2 = ((double)b.first)/b.second;
        
        int x = ceil(t1);
        int y = ceil(t2);
        
        return x<y;
    }
    
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
        int n = dist.size();
        vector<pair<int,int>>arr(n);
        for(int i=0; i<n; i++)
            arr[i]={dist[i],speed[i]};
        
        sort(arr.begin(),arr.end(),cmp);
        
        int ct=1;
        for(int i=1; i<n; i++)
        {
            int newDist = arr[i].first - i*arr[i].second;
            if(newDist<=0)
                break;
            else
                ct=i+1;
        }
        return ct;
    }
};