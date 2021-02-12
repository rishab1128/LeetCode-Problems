class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    void func(int n, int open, int close, string str , vector<string>&ans)
    {
        if(open==n&&close==n)
        {
            ans.push_back(str);
            return;
        }
        if(open<n)
            func(n,open+1,close,str+"(",ans);
        if(close<open)
            func(n,open,close+1,str+")",ans);
    }
    vector<string> generateParenthesis(int n) 
    {
        string str="";
        vector<string>ans;
        func(n,0,0,"",ans);
        return ans;
    }
};