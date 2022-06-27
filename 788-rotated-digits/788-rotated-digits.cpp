class Solution {
public:
    
    set<int>good={2,5,6,9};
    set<int>bad = {3,4,7};
    
    bool check(int x)
    {
        bool flag = 0;
        while(x)
        {
            int rem = x%10;
            if(bad.count(rem))
                return false;
            if(good.count(rem))
                flag=1;
            x/=10;
        }
        return flag;
    }
    
    int rotatedDigits(int n) 
    {
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            if(check(i))
                ans++;
        }
        return ans;
    }
};