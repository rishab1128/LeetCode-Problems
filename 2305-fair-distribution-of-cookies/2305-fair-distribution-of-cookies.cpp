class Solution {
public:
    int ans;
    void recur(vector<int>&arr, int start, vector<int>child, int k)
    {
        if(start==(int)arr.size())
        {
            int maxi = INT_MIN;
            for(auto x: child)
                maxi = max(maxi,x);
            ans = min(ans,maxi);
            return;
        }
        
        for(int i=0; i<k; i++)
        {
            child[i]+=arr[start];
            recur(arr,start+1,child,k);
            child[i]-=arr[start];
            if(!child[i])
                break;
        }
    }
    
    int distributeCookies(vector<int>& arr, int k) 
    {
        ans = INT_MAX;
        vector<int>child(k,0);
        recur(arr,0,child,k);
        return ans;
    }
};