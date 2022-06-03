class Solution {
public:
    
    vector<vector<int>>all;
    
    void genAllSubsets(vector<int>&arr, int idx, vector<int>subset)
    {
        if(idx==(int)arr.size())
        {
            all.push_back(subset);
            return;
        }
        subset.push_back(arr[idx]);
        genAllSubsets(arr,idx+1,subset);
        subset.pop_back();
        genAllSubsets(arr,idx+1,subset);
    }
    
    vector<vector<int>> subsets(vector<int>& arr) 
    {
        all.clear();
        genAllSubsets(arr,0,{});
        return all;
    }
};