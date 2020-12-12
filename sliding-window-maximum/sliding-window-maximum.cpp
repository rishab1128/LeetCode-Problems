#include<bits/stdc++.h>
using namespace std;
​
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) 
    {
        deque<int>dq;
        vector<int>ans;
        int n=arr.size();
        for(int i=0; i<k-1; i++)
        {
            while(!dq.empty()&&arr[dq.back()]<=arr[i])
                dq.pop_back();
            dq.push_back(i);
        }
        for(int i=k-1; i<n; i++)
        {
            while(!dq.empty()&&dq.front()<=i-k)
                dq.pop_front();
            
            while(!dq.empty()&&arr[dq.back()]<=arr[i])
                dq.pop_back();
            
            dq.push_back(i);
            ans.push_back(arr[dq.front()]);
        }
        // while(!dq.empty())
        //     ans.push_back(arr[dq.front()]),dq.pop_front();
        return ans;
        
    }
};
