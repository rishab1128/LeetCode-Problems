class Solution {
public:
    unordered_map<int,int>mp;
    int n;
    map<pair<int,int> , bool>dp;
    
    bool recur(vector<int>&arr, int pos, int k)
    {
        if(pos==arr[n-1])
            return true;
        
        if(!mp.count(pos) || k<=0)
            return false;
        
        if(dp.count({pos,k}))
            return dp[{pos,k}];
            
        bool op1 = recur(arr,pos+k-1,k-1);
        bool op2 = recur(arr,pos+k,k);
        bool op3 = recur(arr,pos+k+1,k+1);
        
        return dp[{pos,k}] = op1|op2|op3;
    }
    
    bool canCross(vector<int>& arr) 
    {
        dp.clear();
        n  = arr.size();
        for(auto x: arr)
            mp[x]=1;
        
        if(arr[0]!=0 || arr[1]!=1)
            return false;
        
        bool ans = recur(arr,1,1) ;
        return ans;
    }
};