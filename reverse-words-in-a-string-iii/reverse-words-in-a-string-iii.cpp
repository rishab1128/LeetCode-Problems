class Solution {
public:
    
    string reverseWords(string str) 
    {
        stringstream s(str); 
        string word;
        string ans="";
        while(s>>word)
        {
            reverse(word.begin(),word.end());
            ans+=word;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};