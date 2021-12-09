class Solution {
public:
    int n;
    int vis[50001];
    bool dfs(vector<int>&arr, int st)
    {
        if(st<0 || st>=arr.size())
            return false;
        if(arr[st]==0)
            return true;
        bool op1=false , op2=false;
        vis[st]=1;
        if(st+arr[st]<n and vis[st+arr[st]]==0)
            op1=dfs(arr,st+arr[st]);
        if(st-arr[st]>=0 and vis[st-arr[st]]==0)
            op2=dfs(arr,st-arr[st]);
        return op1|op2;   
    }
    
    bool canReach(vector<int>& arr, int start) 
    {
        n=arr.size();
        return dfs(arr,start);
    }
};