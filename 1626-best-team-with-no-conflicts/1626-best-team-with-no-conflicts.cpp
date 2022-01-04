class Solution {
public:
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        int n=scores.size();
        vector<pair<int,int>>arr(n);
        for(int i=0; i<n; i++)
            arr[i]={ages[i],scores[i]};
        
        sort(arr.begin(),arr.end());
        
        // for(auto [x,y]: arr)
        //     cout<<x<<" "<<y<<endl;
        
        vector<int>dp(n,0);
        
        dp[0]=arr[0].second;
        for(int i=1; i<n; i++)
        {
            int maxi=arr[i].second;
            for(int j=i-1; j>=0; j--)
            {
                if(arr[i].second>=arr[j].second)
                    maxi=max(maxi , arr[i].second+dp[j]);
            }
            dp[i]=maxi;
        }
        
        // for(auto x: dp)
        //     cout<<x<<" ";
        // cout<<endl;
        
        int ans=*max_element(dp.begin(),dp.end());
        
        return ans;
        
    }
};