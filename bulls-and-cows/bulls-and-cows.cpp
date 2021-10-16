class Solution {
public:
    string getHint(string secret, string guess) 
    {
        map<char,int>mp;
        for(auto x: secret)
            mp[x]++;
        
        int n=secret.size();
        int bulls=0,cows=0;
        for(int i=0; i<n; i++)
        {
            if(secret[i]==guess[i])
            {
                bulls++;
                mp[secret[i]]--;
                if(mp[secret[i]]==0)
                    mp.erase(secret[i]);
            }
        }
        
        for(int i=0; i<n; i++)
        {
            if(secret[i]!=guess[i])
            {
                if(mp.find(guess[i])!=mp.end())
                {
                    cows++;
                    mp[guess[i]]--;
                    if(mp[guess[i]]==0)
                        mp.erase(guess[i]);
                }
            }
            
        }
            
        
        
        string ans=to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;
       
    }
};