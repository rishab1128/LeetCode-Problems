bool comp(const pair<int,int>&a, const pair<int,int>&b)
{
    int x=a.second-a.first;
    int y=b.second-b.first;
    return x>y;
}

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) 
    {
        vector<pair<int,int>>arr;
        for(int i=0; i<tasks.size(); i++)
            arr.push_back({tasks[i][0],tasks[i][1]});
        sort(arr.begin(),arr.end(),comp);
        // for(auto [x,y]: arr)
        //     cout<<x<<" "<<y<<endl;
        // cout<<"--------------------------"<<endl;
        int ans=arr[0].second;
        for(int i=1; i<arr.size(); i++)
        {
            int extra=arr[i-1].second-arr[i-1].first;
            int add=arr[i].second-extra;
            if(add>0)
                ans+=add;
            else
                arr[i].second=extra;
        }
        
        return ans;
    }
};