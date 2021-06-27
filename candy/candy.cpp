class Solution {
public:
    int candy(vector<int>& rate) 
    {
        int n=rate.size();
        vector<int>suff(n,1);
        vector<int>ans(n,1);
        for(int i=n-2; i>=0; i--)
        {
            if(rate[i]>rate[i+1])
                suff[i]=suff[i+1]+1;
            else
                suff[i]=1;
        }
        for(int i=0; i<n; i++)
        {
            if(i==0)
            {
                ans[i]=suff[i];
                continue;
            }
            if(rate[i]>rate[i-1])
                ans[i]=max(suff[i],ans[i-1]+1);
            else
                ans[i]=suff[i];
        }
        int sum=accumulate(ans.begin(),ans.end(),0);
        return sum;
        
    }
};