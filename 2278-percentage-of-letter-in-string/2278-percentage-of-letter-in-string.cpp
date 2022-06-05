class Solution {
public:
    int percentageLetter(string s, char letter) 
    {
        int  n = s.size() , cnt = 0;
        for(auto x: s)
        {
            if(x==letter)
                cnt++;
        }
        int ans =(cnt*100)/n;
        return ans;
        
    }
};