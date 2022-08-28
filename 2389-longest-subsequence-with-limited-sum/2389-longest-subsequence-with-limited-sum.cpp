class Solution {
public:
    vector<int> answerQueries(vector<int>& arr, vector<int>& que) 
    {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (int i = 1; i < arr.size(); ++i)
            arr[i] += arr[i - 1];
        for (auto q: que)
            ans.push_back(upper_bound(arr.begin(), arr.end(), q) - arr.begin());
        return ans;
    }
};