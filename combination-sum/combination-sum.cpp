class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void recur(vector<int>&arr , vector<int>tmp , int target , int idx)
    {
        if(idx>n || target<0 || (idx==n and target>0)) 
            return;
        if(target==0)
        {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(arr[idx]);
        recur(arr,tmp,target-arr[idx],idx);
        tmp.pop_back();
        recur(arr,tmp,target,idx+1);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target)
    {
        n=arr.size();
        ans.clear();
        recur(arr,{},target,0);
        return ans;
    }
};