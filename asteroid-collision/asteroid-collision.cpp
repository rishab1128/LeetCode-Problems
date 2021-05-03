class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>st;
        int n=ast.size();
        for(int i=0; i<n; i++)
        {
            if(ast[i]>0)
                st.push(ast[i]);
            else
            {
                if(st.size()==0 || (st.size()>0  and st.top()<0))
                    st.push(ast[i]);
                else
                {
                    st.push(ast[i]);
                    while((st.size()>0  and st.top()<0) || (st.size()!=1))
                    {
                        int op1=st.top();
                        st.pop();
                        int op2=st.top();
                        st.pop();
                        if(abs(op1)>op2)
                        {
                            int z=0;
                            if(st.size()>0)
                                z=st.top();
                            st.push(op1);
                            if(st.size()==1 || z<0)
                                break;
                        }
                        else if(op2>abs(op1))
                        {
                            st.push(op2);
                            break;
                        }
                        else
                            break;
                            
                    }
                }
            }
        }
        vector<int>ans;
        while(st.size()>0)
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};