class Solution {
public:
    int findLongestChain(vector<vector<int>>& pars) 
    {
        int n=pars.size();
        vector<pair<int,int>>pairs(n);
        for(int i=0; i<n; i++)
        {
            pairs[i].first=pars[i][0];
            pairs[i].second=pars[i][1];
        }
        sort(pairs.begin(),pairs.end());
        int lis[n];
        lis[0]=1;
        for(int i=1; i<n; i++)
        {
            int n1=pairs[i].first;
            lis[i]=1;
            for(int j=0; j<i; j++)
            {
                int n2=pairs[j].second;
                if(n1>n2)
                    lis[i]=max(lis[i],lis[j]+1);
            }
        }
        int ans=1;
        for(auto x: lis)
            ans=max(ans,x);
        return ans;
    }
};