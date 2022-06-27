class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int n = s.size();
        vector<int>zero(n,0) , one(n,0);
        
        if(s[0]=='0')
            zero[0]=1;
        for(int i=1; i<n; i++)
            zero[i]= s[i]=='0' ? 1+zero[i-1] : zero[i-1];
        
        
        if(s[n-1]=='1')
            one[n-1]=1;
        for(int i=n-2; i>=0; i--)
            one[i] = s[i]=='1' ? 1+one[i+1] : one[i+1];
        
        int ct0 = 0, ct1=0;
        for(auto x: s)
        {
            if(x=='0')
                ct0++;
            else if(x=='1')
                ct1++;
        }
        
        int ans = min(ct0,ct1);
        
        for(int i=0; i<n-1; i++)
        {
            int leftFlip = abs(i+1-zero[i]);
            int rightFlip = abs(n-i-1-one[i+1]);
            ans = min({ans,leftFlip+rightFlip});
        }
        
        return ans;
        
    }
};