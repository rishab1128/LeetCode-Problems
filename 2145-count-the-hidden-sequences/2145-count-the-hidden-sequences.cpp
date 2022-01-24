//Refer the comment with pic from : https://leetcode.com/problems/count-the-hidden-sequences/discuss/1709755/JavaC%2B%2BPython-Straight-Forward-Solution-with-Explantion

class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) 
    {
        long long prev=lower , maxi=lower, mini=lower;
        for(int i=0; i<diff.size(); i++)
        {
            long long next=prev+diff[i];
            maxi=max(maxi,next);
            mini=min(mini,next);
            prev=next;
        }
        int ans=(upper-lower)-(maxi-mini)+1;
        return ans<=0 ? 0 : ans;
    }
};