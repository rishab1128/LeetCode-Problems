class Solution {
public:
    vector<vector<string>>ans;
    int n;
    
    bool isPalindrome(string s)
    {
        int n=s.size();
        int i=0,j=n-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    void recur(string s, int idx, vector<string>res)
    {
        if(idx==n)
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=idx; i<n; i++)
        {
            string str = s.substr(idx,i-idx+1);
            if(isPalindrome(str))
            {
                res.push_back(str);
                recur(s,i+1,res);
                res.pop_back();
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