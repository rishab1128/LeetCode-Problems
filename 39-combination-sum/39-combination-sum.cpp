class Solution {
public:
    vector<vector<int>>ans;
    void recur(vector<int>&arr, int target, int idx, vector<int>res, int sum)
    {
        if(idx==(int)arr.size() || sum>target)
            return;
        
        if(sum==target)
        {
            ans.push_back(res);
            return;
        }
        res.push_back(arr[idx]);
        recur(arr,target,idx,res,sum+arr[idx]);
        res.pop_back();
        recur(arr,target,idx+1,res,sum);
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) 
    {
        ans.clear();
        recur(arr,target,0,{},0);
        return ans;
    }
};