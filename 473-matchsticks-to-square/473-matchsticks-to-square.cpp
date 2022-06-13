class Solution {
public:
    bool canPartition(vector<int>& nums, vector<int>& visited, int start_index, int k, int cur_sum, int target)
    {
        
        if(k==1)
            return true;
        if(cur_sum == target)
            return canPartition(nums, visited, 0, k-1, 0,target);
        
        for(int i = start_index; i<nums.size(); i++)
        {
            if(!visited[i])
            {
                visited[i] = 1;
                if(canPartition(nums, visited, i+1, k, cur_sum + nums[i], target))
                    return true;
                visited[i] = 0;
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& nums) 
    {
        int k = 4;
        int sum = 0;
        for(int num:nums)
            sum+=num;
        if(sum%k != 0)
            return false;
        vector<int> visited(nums.size(), 0);
        return canPartition(nums, visited, 0, k, 0, sum/k);
        
    }
};