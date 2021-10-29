class Solution {
public:
    int minPairSum(vector<int>& arr) 
    {
        
        int n=arr.size();
        sort(arr.begin(),arr.end());
        priority_queue<int>pq;
        int i=0,j=n-1;
        while(i<j)
        {
            pq.push(arr[i++]+arr[j--]);
        }
        int ans=pq.top();
        return ans;
    }
};