#include<bits/stdc++.h>
using namespace std;
​
class Solution 
{
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
​
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size()==0)
            return nums1;
        else if(nums2.size()==0)
            return nums2;
        
        stack<int>st;
        int n=nums2.size();
        st.push(nums2[0]);
        map<int,int>mp;
        for(int i=1; i<n; i++)
        {
            int next=nums2[i];
            while(next>st.top()&&!st.empty())
            {
                mp[st.top()]=next;
                st.pop();
