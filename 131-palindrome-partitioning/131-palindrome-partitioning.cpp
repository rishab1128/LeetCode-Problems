class Solution {
public:
    vector<vector<string>>ans;
    int n;
    bool isPalindrome(string s)
    {
        string t=s;
        reverse(s.begin(),s.end());
        return t==s;
    }
    
    void recur(string s , int idx , vector<string>tmp)
    {
        if(idx==n)
        {
            ans.push_back(tmp);
            return;
        }
        for(int i=idx; i<n; i++)
        {
            string str=s.substr(idx,i-idx+1);
            if(isPalindrome(str))
            {
                tmp.push_back(str);
                recur(s,i+1,tmp);
                tmp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) 
    {
        n=s.size();
        ans.clear();
        recur(s,0,{});
        return ans;
    }
};