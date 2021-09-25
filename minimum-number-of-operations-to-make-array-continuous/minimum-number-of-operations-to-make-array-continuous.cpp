//Refer  : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/discuss/1470853/Python-Binary-Search-Clean-and-Concise


class Solution {
public:
    
    int minOperations(vector<int>& arr) 
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        int m=arr.size();
        int ans=1e9;
        for(int i=0; i<m; i++)
        {
            int j=upper_bound(arr.begin()+i,arr.end(),arr[i]+n-1)-arr.begin();
            int uniqueLen=j-i;
            int cost=n-uniqueLen;
            ans=min(ans,cost);
        }
        return ans;
    }
};