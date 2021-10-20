class Solution {
public:
    //O(1) space
    string reverseWords(string s) {
        stringstream all(s); 
        string word,ans = "";
        while (all >> word)
            ans = word + " " + ans;
        return ans.substr(0,ans.length()-1);
    }
};