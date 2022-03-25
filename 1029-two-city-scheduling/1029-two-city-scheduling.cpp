bool cmp(const vector<int>&a , const vector<int>&b)
{
    return (a[1]-a[0]>b[1]-b[0]);
}
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        int n=(int)costs.size()/2;
        sort(costs.begin(),costs.end(),cmp);
        int ans=0;
        for(int i=0; i<2*n; i++)
        {
            if(i<n)
                ans+=costs[i][0];
            else
                ans+=costs[i][1];
        }
        return ans;
    
    }
};