class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    vector<int> partitionLabels(string s) 
    {
        int n=s.size();
        unordered_map<char,int>mp;
        vector<int>ans;
        for(int i=0; i<n; i++)
        {
            mp[s[i]]=i;
        }
        for(int i=0; i<n; i++)
        {
            int start=i,end=mp[s[i]],maxi=mp[s[i]];
            if(start!=end)
            {
                for(int j=start+1; j<end; j++)
                {
                    maxi=max(maxi,mp[s[j]]);
                    end=maxi;
                }
                ans.push_back(maxi-start+1);
                i=maxi;
            }
            else
            {
                ans.push_back(1);
            }
            
        }
        return ans;
        
    }
};