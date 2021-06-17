class Solution {
public:
    bool isPalin(string s)
    {
        string t=s;
        reverse(s.begin(),s.end());
        return s==t;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        //Optimised : O(n*k^2) algo n=words.size() , k=words[i].size();
        //Assumption: No duplicated string in the given map/dictionary
        int n=words.size();
        unordered_map<string,int>mp;
        vector<vector<int>>ans;
        for(int i=0; i<n; i++)
        {
            string t=words[i];
            reverse(t.begin(),t.end());
            mp[t]=i;
        }
        
        // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
        if(mp.find("")!=mp.end())
        {
            for(int i=0; i<n; i++)
            {
                if(isPalin(words[i]) &&  i!=mp[""]) //(1) if self is palindrome, here ans covers concatenate("", self) 
                    ans.push_back({mp[""],i});
            }
        }
        
        for(int i=0; i<n; i++)
        {
            int m=words[i].size();
            string s=words[i];
            
            for(int j=0; j<m; j++)
            {
                string left=s.substr(0,j);
                string right=s.substr(j,m-j);
                
                if( isPalin(right) &&  mp.find(left) != mp.end() && mp[left]!=i ) // (2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
                    ans.push_back({i,mp[left]});
                
                if( isPalin(left)  && mp.find(right) != mp.end() && mp[right]!=i)
                    ans.push_back({mp[right],i});
            }
        }
        
        return ans;
        
        
    }
};