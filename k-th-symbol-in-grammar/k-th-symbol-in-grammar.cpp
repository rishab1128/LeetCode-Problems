class Solution {
public:
    int kthGrammar(int n, int k) 
    {
        long long start=(1<<(n-1))+(k-1);
        //cout<<start<<endl;
        stack<long long>st;
        while(start>=1)
        {
            st.push(start);
            start/=2;
        }
        int res=0;
        st.pop();
        while(st.size()>0)
        {
            int tp=st.top();
            st.pop();
            if(tp%2==0)
                res^=0;
            else
                res^=1;
        }
        return res;
        
    }
};