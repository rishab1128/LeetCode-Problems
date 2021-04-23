class Solution {
public:
    //O(N) solution
    bool canJump(vector<int>& nums) 
    {
        int n=nums.size();
        if(n<2)
            return true;
        int jump=1 , maxi=nums[0] , curr=nums[0];
        int i=0;
        while(i<n-1)
        {
            maxi=max(maxi,i+nums[i]);
            cout<<maxi<<endl;
            if(curr==i)
            {
                jump++;
                if(curr>=maxi)
                    return false;
                curr=maxi;
            }
            i++;
        }
        return true;
    }
};