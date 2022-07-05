class Solution {
public:
    unordered_map<char,vector<char>>mp;
    
    vector<string>recur(string digits)
    {
        if(digits.size()==0)
        {
            return {""};
        }
        char ch = digits[0];
        vector<string>futureState = recur(digits.substr(1));
        vector<string>ans;
        for(int i=0; i<mp[ch].size(); i++)
        {
            char front = mp[ch][i];
            string finalWord;
            for(auto word : futureState)
            {
                finalWord="";
                finalWord+=front;
                finalWord+=word;
                ans.push_back(finalWord);
            }
        }
        return ans;
    }
    
    vector<string> letterCombinations(string digits) 
    {
        if(digits.size()==0)
            return {};
        mp.clear();
        char alpha = 'a';
        for(char ch='2'; ch<='9'; ch++)
        {
            if(ch!='7' and ch!='9')
            {
                for(int i=0; i<3; i++){
                    mp[ch].push_back(alpha);
                    alpha++;
                }    
            }
            else
            {
                for(int i=0; i<4; i++){
                    mp[ch].push_back(alpha);
                    alpha++;
                }    
            }
        }
        
        vector<string> ans = recur(digits);
        return ans;
    }
};