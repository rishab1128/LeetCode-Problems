class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        sort(arr.begin() , arr.end());
        int n=arr.size();
        int diff=INT_MAX;
        
        vector<vector<int>>ans;
        for(int i=0; i<n-1; i++)
            diff=min(diff , arr[i+1]-arr[i]);
        
        for(int i=0; i<n-1; i++)
        {
            if(arr[i+1]-arr[i]==diff)
                ans.push_back({arr[i],arr[i+1]});
        }
        
        return ans;
        
    }
};