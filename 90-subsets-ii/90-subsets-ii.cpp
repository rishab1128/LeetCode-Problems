class Solution {
public:
    
    vector<vector<int>>all;
    
    void recur(vector<int>&arr, int idx, vector<int>subset)
    {
        all.push_back(subset);
        for(int i=idx; i<(int)arr.size(); i++)
        {
            if(i!=idx and arr[i]==arr[i-1])
                continue;
            subset.push_back(arr[i]);
            recur(arr,i+1,subset);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        all.clear();
        sort(arr.begin(),arr.end());
        recur(arr,0,{});
        return all;
    }
};