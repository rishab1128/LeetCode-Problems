class Solution {
public:
    int ones,zeros;
    int func(string s , int n)
    {
        int ct=0;
        for(int i=0; i<s.size() ; i++)
        {
            if(s[i]-'0'!=n)
                ct++;
            n^=1;
        }
        return ct/2;
    }
    
    int minSwaps(string s) 
    {
        int n=s.size();
        ones=0,zeros=0;
        for(auto x: s)
        {
            if(x=='1')
                ones++;
            else
                zeros++;
        }
        if(abs(ones-zeros)>1)
            return -1;
        if(ones>zeros)
            return func(s,1);
        else if(zeros>ones)
            return func(s,0);
        return min(func(s,1) , func(s,0));
    }
};