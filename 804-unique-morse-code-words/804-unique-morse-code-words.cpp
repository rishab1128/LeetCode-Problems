class Solution {
public:
    
    vector<string>arr;
    
    string transform(string &s)
    {
        string ans = "";
        for(auto &ch : s)
        {
            ans+=arr[ch-'a'];
        }
        return ans;
    }
    
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        arr = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string>st;
        for(auto &word: words)
        {
            st.insert(transform(word));
        }
        int ans = st.size();
        return ans;
        
    }
};