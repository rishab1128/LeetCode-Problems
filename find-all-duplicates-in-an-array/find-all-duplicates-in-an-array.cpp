class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        //O(N) time and O(1) space
        //See notes
        vector<int>ans;
        for(int i=0; i<nums.size(); i++)
        {
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
            if(nums[abs(nums[i])-1]>0)
                ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};