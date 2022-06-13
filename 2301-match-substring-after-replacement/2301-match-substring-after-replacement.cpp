class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) 
    {
        map<char,set<char>>mp;
        for(auto arr : mappings)
        {
            char ch1 = arr[0] , ch2 = arr[1];
            mp[ch1].insert(ch2);
        }
        int n = s.size();
        int len = sub.size();
        for(int i=0; i<=n-len; i++)
        {
            string str = s.substr(i,len);
            bool flag = true;
            for(int j=0; j<len; j++)
            {
                if(sub[j]==str[j])
                    continue;
                else
                {
                    char ch1 =sub[j] , ch2 = str[j];
                    if(mp[ch1].find(ch2)==mp[ch1].end()){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
                return true;
        }
        return false;
    }
};