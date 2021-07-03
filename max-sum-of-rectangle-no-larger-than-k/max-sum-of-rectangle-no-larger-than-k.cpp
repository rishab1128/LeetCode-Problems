class Solution {
public:
    //Using approach 1 given in the Solution
    //Sub-problem -> First solve the same ques for 1-D array and then move to 2-D array
    int maxSumSubarray(vector<int>&arr , int k)
    {
        int n=arr.size() ; 
        int pref=0;
        int dp[n]; //dp[i] => Stores the max sub-array sum <= k and ending at i;
        // dp[0]=(arr[0]<=k) ? arr[0] : INT_MIN;
        // pref+=arr[0];
        set<int>st;
        st.insert(pref);
        
        for(int i=0; i<n; i++)
        {
            pref+=arr[i];
            //Search in the set for an ele such that ele (is just greater than or equal to)>= pref-k
            auto it=st.lower_bound(pref-k);
            if(it!=st.end())
            {
                int ele=(*it);
                dp[i]=pref-ele;
            }
            else
                dp[i]=INT_MIN;
            st.insert(pref);
        }
        
        int ans=INT_MIN;
        
        // for(auto x: arr)
        //     cout<<x<<" ";
        // cout<<endl;
        
        for(auto x: dp)
        {
            //cout<<x<<" ";
            ans=max(ans,x);
        }
        //cout<<endl;
        //cout<<"--------------------------"<<endl;
            
        
        return ans;
        
    }
    
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) 
    {
        int n=mat.size(), m=mat[0].size();
        int ans=INT_MIN;
        for(int t=0; t<n; t++)
        {
            vector<int>arr(m,0);
            for(int i=t; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    arr[j]+=mat[i][j];
                }
                int tmp=maxSumSubarray(arr,k);
                ans=max(ans,tmp);
            }
        }
        
        return ans;
        
    }
};