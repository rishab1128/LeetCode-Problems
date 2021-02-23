class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        //Using Stack
        int n=nums.size();
        if(n==0)
            return nums;
        vector<int>ans(n);
        stack<int>st;
        ans[n-1]=-1;
        st.push(n-1);
        for(int i=n-2; i>=0; --i)
        {
            int idx=st.top();
            if(nums[idx]>nums[i])
            {
                ans[i]=nums[idx];
                st.push(i);
            }
            else
            {
                while(st.size()>0 && nums[i]>=nums[st.top()])
                {
                    st.pop();
                }
                if(st.empty())
                    ans[i]=-1;
                else
                    ans[i]=nums[st.top()];
                st.push(i);
            }
        }
        
        for(int i=n-1; i>=0; --i)
        {
            int idx=st.top();
            if(nums[idx]>nums[i])
            {
                ans[i]=nums[idx];
                st.push(i);
            }
            else
            {
                while(st.size()>0 && nums[i]>=nums[st.top()])
                {
                    st.pop();
                }
                if(st.empty())
                    ans[i]=-1;
                else
                    ans[i]=nums[st.top()];
                st.push(i);
            }
        }
        
        return ans;
        
    }
};