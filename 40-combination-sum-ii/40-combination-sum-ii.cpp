class Solution {
public:
    vector<vector<int>>ans;
    
    void recur(vector<int>&arr, int target, int idx, int sum, vector<int>tmp)
    {
        if(sum>target || idx>arr.size())
            return;
        if(sum==target)
        {
            ans.push_back(tmp);
            return;
        }
        for(int i=idx; i<arr.size(); i++)
        {
            if(i!=idx and arr[i]==arr[i-1])
                continue;
            tmp.push_back(arr[i]);
            recur(arr,target,i+1,sum+arr[i],tmp);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) 
    {
        sort(arr.begin(),arr.end());
        recur(arr,target,0,0,{});
        return ans;
    }
};