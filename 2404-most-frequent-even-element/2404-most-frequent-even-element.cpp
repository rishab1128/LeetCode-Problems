class Solution {
public:
    int mostFrequentEven(vector<int>& arr) 
    {
        unordered_map<int,int>mp;
        for(auto &x: arr)
        {
            if(x%2==0)
                mp[x]++;
        }
        
        int ans = -1 , maxi = 0;
        for(auto &[ele,freq] : mp)
        {
            if(freq > maxi)
            {
                maxi = freq;
                ans = ele;
            }
            else if(freq == maxi)
                ans = min(ans,ele);
        }
        return ans;
        
    }
};