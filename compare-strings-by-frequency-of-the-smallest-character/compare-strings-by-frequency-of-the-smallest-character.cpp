class Solution {
public:
    int func(string s)
    {
        sort(s.begin(), s.end());
        char ch=s[0];
        int ct=0;
        for(auto x: s)
        {
            if(x==ch)
                ct++;
            else
                break;
        }
        return ct;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& que, vector<string>& words) 
    {
        int n=words.size() , m=que.size();
        vector<int>freq(n);
        for(int i=0; i<n; i++)
            freq[i]=func(words[i]);
        
        sort(freq.begin() , freq.end());
        
        vector<int>ans(m);
        for(int i=0; i<m; i++)
        {
            int fq=func(que[i]);
            int pos=upper_bound(freq.begin() , freq.end() , fq)-freq.begin();
            ans[i]=n-pos;
        }
        
        return ans;
        
        
    }
};