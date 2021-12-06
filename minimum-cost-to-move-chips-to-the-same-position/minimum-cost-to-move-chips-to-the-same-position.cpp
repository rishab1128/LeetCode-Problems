class Solution {
public:
    int minCostToMoveChips(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans=INT_MAX;
        for(int i=0; i<n; i++)
        {
            int ct=0;
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                {
                    int diff=abs(arr[i]-arr[j]);
                    if(diff%2)
                        ct+=1;
                }
            }
            ans=min(ans,ct);
        }
        return ans;
    }
};