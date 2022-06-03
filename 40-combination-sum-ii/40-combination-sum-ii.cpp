class Solution {
public:
    
    vector<vector<int>>ans;
    int n;
    
    void recur(vector<int>&arr, int target, int idx, vector<int>res)
    {
        if((target<0)||(idx==n and target>0))
            return;
        
        if(target==0)
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=idx; i<n; i++)
        {
            if(i!=idx and arr[i]==arr[i-1])
                continue;
            res.push_back(arr[i]);
            recur(arr,target-arr[i],i+1,res);
            res.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        n=arr.size();
        ans.clear();
        sort(arr.begin(),arr.end());
        recur(arr,target,0,{});
        return ans;
    }
};