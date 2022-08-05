//Approach 1 - TC : O(n!) SC : O(N) (using map) -> ignoring recursion stack
class Solution {
public:
    
    void recur(vector<int>&arr, vector<int>tmp, unordered_map<int,int>&mp , vector<vector<int>>&ans)
    {
        if(tmp.size()==arr.size())
        {
            ans.push_back(tmp);
            return;
        }
        for(int i=0; i<arr.size(); i++)
        {
            if(!mp[i])
            {
                mp[i] = 1;
                tmp.push_back(arr[i]);
                recur(arr,tmp,mp,ans);
                mp[i] = 0;
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& arr) 
    {
        vector<vector<int>>ans;
        unordered_map<int,int>mp;
        recur(arr,{},mp,ans);
        return ans;
    }
};