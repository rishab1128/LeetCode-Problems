class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        int m=rolls.size() , sumM=0;
        for(auto x: rolls)
            sumM+=x;
        int sumN=mean*(m+n)-sumM;
        int quo=sumN/n;
        int rem=sumN%n;
        if(quo==0 || quo>6 || (rem>0 and quo+1>6) || sumN<=0)
            return {};
        
        vector<int>ans;
        for(int i=1; i<=rem; i++)
            ans.push_back(quo+1);
        for(int i=1; i<=n-rem; i++)
            ans.push_back(quo);
        
        return ans;
    }
};