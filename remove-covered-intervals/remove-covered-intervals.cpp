bool comp(const pair<int,int>&a , const pair<int,int>&b)
{
    if(a.first==b.first)
        return a.second>b.second;
    return a.first<b.first;
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) 
    {
        int n=inter.size();
        vector<pair<int,int>>arr;
        for(int i=0; i<n; i++)
        {
            arr.push_back({inter[i][0],inter[i][1]});
        }
        sort(arr.begin(),arr.end(),comp);
        for(auto [x,y] : arr)
            cout<<x<<" "<<y<<endl;
        int ct=0 , maxi=arr[0].second;
        for(int i=1; i<n; i++)
        {
            if(arr[i].second<=maxi)
                ct++;
            else
                maxi=arr[i].second;
        }
        return n-ct;
    }
};