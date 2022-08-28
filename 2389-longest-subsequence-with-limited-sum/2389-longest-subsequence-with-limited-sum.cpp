class Solution {
public:
    vector<int> answerQueries(vector<int>& arr, vector<int>& que) 
    {
        int m = que.size();
        vector<int>ans(m);
        for(int i=0; i<m; i++)
        {
            int target = que[i];
            priority_queue<int>pq;
            int sum = 0;
            for(int j=0; j<arr.size(); j++)
            {
                sum+=arr[j];
                if(sum<=target)
                    pq.push(arr[j]);
                else
                {
                    if(pq.size() and pq.top()>arr[j])
                    {
                        sum-=pq.top();
                        pq.pop();
                        pq.push(arr[j]);
                    }
                    else
                        sum-=arr[j];
                }
            }
            ans[i] = pq.size();
        }
        return ans;
    }
};