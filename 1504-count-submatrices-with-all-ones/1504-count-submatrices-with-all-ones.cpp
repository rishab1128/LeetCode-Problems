class Solution {
public:
    
    int count(vector<int>&arr)
    {
        int n = arr.size();
        stack<int>st;
        vector<int>dp(n,0);
        
        //dp[j] := stores the total number of rectangles ending at boundary column j 
        
        for(int j=0; j<n; j++)
        {
            while(st.size() and arr[st.top()]>=arr[j])
                st.pop();
            if(st.empty())
                dp[j] = arr[j]*(j+1);
            else
            {
                int prevIdx = st.top();
                dp[j] = dp[prevIdx];
                dp[j] += arr[j]*(j-prevIdx);
            }
            st.push(j);
        }
        
        int ans = accumulate(dp.begin(),dp.end(),0);
        return ans;
    }
    
    int numSubmat(vector<vector<int>>& arr) 
    {
        int m = arr.size() , n = arr[0].size();
        vector<int>ht(n,0);
        int ans = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++){
                if(arr[i][j])
                    ht[j]+=arr[i][j];
                else
                    ht[j]=0;
            }
                
            
            ans += count(ht);
        }
        return ans;
        
    }
};