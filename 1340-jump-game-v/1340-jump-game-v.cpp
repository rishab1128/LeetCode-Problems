class Solution {
public:
    
    int n , d;
    vector<int>arr;
    int dp[1001] = {};
    
    int recur(int i) 
    {
        if (dp[i]) 
            return dp[i];
        
        int res=1;
        
        for (int j = i + 1; j <= min(i + d, n - 1) ; j++){
            if(arr[j]>=arr[i])
                break;
            res = max(res, 1 + recur(j));
        }
            
        
        for (int j = i - 1; j >= max(0, i - d) ; j--){
            if(arr[j]>=arr[i])
                break;
            res = max(res, 1 + recur(j));
        }
            
        
        return dp[i] = res;
    }
    
    int maxJumps(vector<int>& arr, int d) 
    {
        this->arr=arr;
        this->d=d;
        n=arr.size();
        
        int ans=1;
        
        for (int i = 0; i < n; ++i)
            ans = max(ans, recur(i));
        
        return ans;
    }
};