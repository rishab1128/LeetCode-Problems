bool cmp(const string&a , const string&b)
{
    return a.size()<b.size();
}
class Solution {
public:
    
    int longestStrChain(vector<string>& words)
    {
        sort(words.begin() , words.end() , cmp);
        unordered_map<string,int>dp;
        int ans=1;
        for(auto w: words)
        {
            for(int i=0; i<w.size(); i++)
            {
                string predecessor=w.substr(0,i)+w.substr(i+1);
                if(dp.find(predecessor)!=dp.end())
                    dp[w]=max(dp[w],dp[predecessor]+1);
                else
                    dp[w]=max(dp[w],1);
            }
            ans=max(ans,dp[w]);
        }
        return ans;
    }
};