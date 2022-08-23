class Solution {
public:
    
    void removeLeadingZeros(string& ans)
    {
        int idx = -1;
        
        for(int i=0; i<ans.size(); i++)
        {
            if(ans[i]!='0')
            {
                idx = i;
                break;
            }
        }
        
        if(idx!=-1)
            ans = ans.substr(idx);
        else
            ans = "";
    }
    
    string largestPalindromic(string s) 
    {
        int n = s.size();
        map<char,int>mp;
        for(auto ch : s)
            mp[ch]++;
        
        
        char middle = '*';
        string ans = "";
        
        for(auto itr = mp.rbegin() ; itr!=mp.rend() ; itr++)
        {
            char ch = itr->first;
            int freq = itr->second;
            
            int quo = freq/2;
            int rem = freq%2;
            
            if(ans.empty() and middle=='*' and ch=='0')
            {
                ans = "0";
                return ans;
            }
            string t(quo,ch);
            ans+=t;
            if(rem and middle=='*')
            {
                middle = ch;
            }
        }
        
        removeLeadingZeros(ans);
        
        // cout<<ans<<endl;
        
        string t = ans;
        reverse(t.begin(),t.end());
        if(middle!='*')
        {
            ans+=middle;
            ans+=t;
        }
        else
            ans+=t;
        
        return ans;
        
    }
};