class Solution {
public:
    //Time : O(N)
    //Space : O(N)
    int firstMissingPositive(vector<int>& arr) 
    {
        map<int,int>mp;
        for(auto x: arr)
            mp[x]=1;
        int n=arr.size();
        for(int i=1; i<=n; i++)
        {
            if(mp.find(i)==mp.end())
                return i;
        }
        return n+1;
        
    }
};