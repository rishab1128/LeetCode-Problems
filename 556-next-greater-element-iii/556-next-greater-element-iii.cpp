class Solution {
public:
    int nextGreaterElement(int num) 
    {
        //Similar to Next Greater Permutation
        string s = to_string(num);
        int idx = -1;
        int n = s.size();
        for(int i=n-2; i>=0; i--)
        {
            if(s[i]<s[i+1])
            {
                idx=i;
                break;
            }
        }
        if(idx==-1)
            return -1;
        
        int idx2 = -1; 
        long long maxi = LLONG_MAX;
        for(int j=idx+1; j<n; j++)
        {
            int x1 = s[j]-'0' , x2 = s[idx]-'0';
            if(x1>x2 and x1<maxi)
            {
                maxi = x1;
                idx2 = j;
            }
        }
        
        swap(s[idx],s[idx2]);
        
        sort(s.begin()+idx+1,s.end());
        
        long long ans = stol(s);
        
        if(ans>INT_MAX)
            return -1;
        
        return ans;
        
    }
};