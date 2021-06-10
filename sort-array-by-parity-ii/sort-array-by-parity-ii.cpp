class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) 
    {
        int i=0, j=1 , n=nums.size();
        while(i<n and j<n)
        {
            if(i<n and nums[i]%2==0)
                i+=2;
            if(j<n and nums[j]%2==1)
                j+=2;
            else
                swap(nums[i],nums[j]);
        }
        return nums;
        
        
    }
};