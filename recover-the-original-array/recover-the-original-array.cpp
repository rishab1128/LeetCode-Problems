class Solution {
public:
    multiset<int>st;
    
    vector<int>check(int k)
    {
        multiset<int>tmp;
        vector<int>ans;
        while(st.size()>0)
        {
            auto it=st.begin();
            int X1=(*it);  //X1=X-k;
            int X=X1+k;
            int X2=X+k;
            if(st.find(X2)!=st.end())
            {
                ans.push_back(X);
                st.erase(it);
                st.erase(st.find(X2));
                tmp.insert(X1);
                tmp.insert(X2);
            }
            else
            {
                for(auto x: tmp)
                    st.insert(x);
                return {-1};
            }
        }
        return ans;
    }
    
    vector<int> recoverArray(vector<int>& arr) 
    {
        int m=arr.size();
        sort(arr.begin(),arr.end());
        for(auto x: arr)
            st.insert(x);
        
        //Try every possible k
        
        int X1=arr[0];  //X1=X-k
        for(int i=1; i<m; i++)
        {
            int X2=arr[i]; //Assume , X2=X+k
            if((X1+X2)%2==0)
            {
                int X=(X1+X2)/2;
                int k=(X2-X1)/2;
                if(k>0)
                {
                    vector<int>ans=check(k);
                    if(ans[0]!=-1)
                        return ans;
                }
            }
        }
        
        return {-1};
        
    }
};