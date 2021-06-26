#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<
    int,
    null_type,
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_multiset;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>ans(n,0);
        ordered_multiset st;
        st.insert(nums[n-1]);
        for(int i=n-2; i>=0; i--)
        {
            ans[i]=st.order_of_key(nums[i]);
            st.insert(nums[i]);
        }
        return ans;
        
    }
};