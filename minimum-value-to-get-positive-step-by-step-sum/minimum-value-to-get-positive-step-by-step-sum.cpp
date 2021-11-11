class Solution {
public:
    int minStartValue(vector<int>& arr)
    {
        int sum=0 , mini=INT_MAX , ans=1;
        for(auto x: arr)
        {
            sum+=x;
            mini=min(mini,sum);
        }
        if(mini<0)
            ans=abs(mini)+1;
        return ans;
    }
};