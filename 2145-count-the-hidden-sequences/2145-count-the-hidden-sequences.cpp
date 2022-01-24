//Refer 1st comment from : https://leetcode.com/problems/count-the-hidden-sequences/discuss/1709755/JavaC%2B%2BPython-Straight-Forward-Solution-with-Explantion

class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) 
    {
        int n=diff.size();
        vector<long long>pref(n);
        pref[0]=diff[0];
        long long mini=pref[0],maxi=pref[0];
        for(int i=1; i<n; i++){
            pref[i]=pref[i-1]+diff[i];
            mini=min(mini,pref[i]);
            maxi=max(maxi,pref[i]);
        }
        
        //Let x be the starting element
        int cnt=0;
        for(int x=lower; x<=upper; x++)
        {
            if(x+mini>=lower and x+maxi<=upper)
                cnt++;
        }
        
        return cnt;
    }
};