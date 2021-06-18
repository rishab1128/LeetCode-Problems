class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        map<int,int>mp;
        for(auto x: target)
            mp[x]=1;
        vector<string>ans;
        for(int i=1; i<=n; i++)
        {
            if(i>target[target.size()-1])
                break;
            if(mp[i])
                ans.push_back("Push");
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};