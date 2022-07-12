class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newInter) 
    {
        vector<vector<int>>ans;
        ans.push_back(newInter);
        for(auto arr : inter)
        {
            int start = arr[0] , end = arr[1];
            vector<int>arr2 = ans.back();
            if(start>arr2[1])
                ans.push_back({start,end});
            else if(end<arr2[0])
            {
                ans.pop_back();
                ans.push_back(arr);
                ans.push_back(arr2);
            }
            else if(end>=arr2[0])
            {
                ans.pop_back();
                ans.push_back({min(start,arr2[0]) , max(end,arr2[1])});
            }
        }
        return ans;
        
    }
};