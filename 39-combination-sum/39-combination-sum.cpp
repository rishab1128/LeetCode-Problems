class Solution {
public:
    vector<vector<int>>ans;
    void recur(vector<int>&arr, int idx, int sum, int target , vector<int>path)
    {
        if(sum>target || idx==arr.size())
            return;
        if(sum==target)
        {
            ans.push_back(path);
            return;
        }
        path.push_back(arr[idx]);
        recur(arr,idx,sum+arr[idx],target,path);
        path.pop_back();
        recur(arr,idx+1,sum,target,path);
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) 
    {
        recur(arr,0,0,target,{});
        return ans;
    }
};