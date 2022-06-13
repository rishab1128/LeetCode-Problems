class Solution {
public:
    long long distinctNames(vector<string>& arr) 
    {
        
        map<char,vector<string>>mp1;
        map<string,vector<char>>mp2;
        map<pair<char,char>,int>mp3;
        
        for(auto word : arr)
        {
            char ch = word[0];
            string str = word.substr(1);
            mp1[ch].push_back(str);
            if(!mp2.count(str))
                mp2[str].push_back(ch);
            else
            {
                for(auto ch2 : mp2[str])
                {
                    pair<char,char> p1 = {ch,ch2};
                    pair<char,char> p2 = {ch2,ch};
                    mp3[p1]++;
                    mp3[p2]++;
                }
                mp2[str].push_back(ch);
            }
        }
        
        long long ans = 0;
        for(auto [ch1 , vec1] : mp1)
        {
            int m1 = vec1.size();
            for(auto [ch2 , vec2] : mp1)
            {
                int m2 = vec2.size();
                if(ch1!=ch2)
                {
                    long long eff1 = m1-mp3[{ch1,ch2}];
                    long long eff2 = m2-mp3[{ch1,ch2}];
                    ans+=(eff1*eff2);
                }
            }
        }
        
        return ans;
        
        
    }
};