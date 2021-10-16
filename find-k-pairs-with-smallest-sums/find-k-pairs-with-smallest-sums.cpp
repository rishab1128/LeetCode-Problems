class Solution {
public:
    //Operator Overloading in PQ
    struct compare{
      bool operator() (const vector<int>&a , const vector<int>&b)
      {
          return a[0]+a[1]>b[0]+b[1];
      } 
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& arr1, vector<int>& arr2, int k) 
    {
        int n=arr1.size() , m=arr2.size();
        
        priority_queue<vector<int> , vector<vector<int>> , compare> pq;
        
        for(int i=0; i<min(n,k); i++)
            pq.push({arr1[i] , arr2[0] , 0});
        
        vector<vector<int>>ans;
        while(k>0 and pq.size()>0)
        {
            auto top=pq.top();
            pq.pop();
            ans.push_back({top[0],top[1]});
            int idx=top[2];
            if(idx+1<m)
                pq.push({top[0] , arr2[idx+1] , idx+1});
            k--;
        }
        
        return ans;
        
    }
};