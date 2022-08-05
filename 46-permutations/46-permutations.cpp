//Approach 1 - TC : O(n*n!) SC : O(N) (only for recursion stack) - no extra space(for map) like prev approach
class Solution {
public:
    
    void recur(vector<int>arr, int idx, vector<vector<int>>&ans)
    {
        if(idx==arr.size()-1)
        {
            ans.push_back(arr);
            return;
        }
        for(int i=idx; i<arr.size(); i++)
        {
            swap(arr[idx],arr[i]);
            recur(arr,idx+1,ans);
            swap(arr[idx],arr[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& arr) 
    {
        vector<vector<int>>ans;
        recur(arr,0,ans);
        return ans;
    }
};