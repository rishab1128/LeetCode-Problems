class Solution {
public:
    //Using Min Heap and concepts similar to merging K-sorted lists
    //TC : O(K*logK)
    int kthSmallest(vector<vector<int>>& mat, int k) 
    {
        int m=mat.size() , n=mat[0].size();
        
        priority_queue<vector<int> , vector<vector<int>> , greater<>> minHeap;
        
        for(int i=0; i<min(m,k); i++)
            minHeap.push({mat[i][0] , i , 0});
        
        int ans=-1;
        while(k>0)
        {
            auto top=minHeap.top();
            minHeap.pop();
            ans=top[0];
            int r=top[1] , c=top[2];
            if(c+1<n)
                minHeap.push({mat[r][c+1] , r , c+1});
            k--;
        }
        
        return ans;
        
        
    }
};