class Solution {
public:
    int searchInsert(vector<int>& arr, int target) 
    {
        int pos=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
        return pos;
    }
};