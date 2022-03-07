class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& arr) 
    {
        int n=arr.size();
        stack<long long>st;
        st.push(arr[0]);
        for(int i=1; i<n; i++)
        {
            long long t1=st.top() , t2=arr[i];
            long long gcd=__gcd(t1,t2);
            if(gcd>1)
            {
                long long x=arr[i];
                while(st.size()>0 and __gcd(st.top(),x)>1)
                {
                    long long t1=st.top() , t2=x;
                    long long gcd=__gcd(t1,t2);
                    long long lcm=(t1*t2)/gcd;
                    st.pop();
                    x=lcm;
                }
                st.push(x);
            }
            else
                st.push(arr[i]);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
        
    }
};