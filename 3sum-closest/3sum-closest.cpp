class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cl=INT_MAX;
        for(int i=0; i<n-2; i++)
        {
            int left=i+1,right=n-1;
            int z=target-nums[i];
            while(left<right)
            {
                if(nums[left]+nums[right]<z)
                {
                    int s=nums[i]+nums[left]+nums[right];
                    if(cl==INT_MAX || abs(s-target)<abs(cl-target))
                        cl=s;
                    left++;
                }
                  
                else if(nums[left]+nums[right]>z)
                {
                    int s=nums[i]+nums[left]+nums[right];
                    if(cl==INT_MAX || abs(s-target)<abs(cl-target))
                        cl=s;
                    right--;
                }
                
                else
                    return target;
            }
        }
        return cl;
        
    }
};