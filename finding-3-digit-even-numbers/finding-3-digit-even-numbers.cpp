class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) 
    {
        vector<int>ans;
        set<int>st;
        int n=arr.size();
        for(int i=0; i<n; i++)
        {
            if(arr[i]==0)
                continue;
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                {
                    for(int k=0; k<n; k++)
                    {
                        if(k!=j and k!=i and arr[k]%2==0)
                        {
                            int num=arr[i]*100+arr[j]*10+arr[k];
                            st.insert(num);
                        }
                    }
                }
            }
        }
        
        for(auto x: st)
            ans.push_back(x);
        
        return ans;
        
    }
};