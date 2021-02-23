class Solution 
{
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }

    vector<int> dailyTemperatures(vector<int>& T) 
    {
        //Without using stack
        int n=T.size();
        vector<int>ans(n,0);
        for(int i=n-2; i>=0; --i)
        {
            int j=i+1;
            if(T[j]>T[i])
                ans[i]=1;
            else 
            {
                while(T[j]<=T[i]&&ans[j]!=0)
                {
                    j=j+ans[j];
                }
                if(T[j]>T[i])
                    ans[i]=j-i;
            }
        }
        return ans;
    }
};