class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int closestCost(vector<int>& base, vector<int>& top, int target) 
    {
        unordered_set<int>st={0};
        unordered_set<int>cp;
        for(auto x: top)
        {
            //cout<<st.size()<<endl;
            cp=st;
            for(auto y: st)
            {
                cp.insert(y+x);
                cp.insert(y+2*x);
            }
            st=cp;
            //cout<<st.size()<<endl;
        }
        // for(auto x: st)
        //     cout<<x<<" ";
        // cout<<endl;
        int res=INT_MAX;
        for(auto x: base)
        {
            for(auto y: st)
            {
                int z=x+y;
                if(abs(target-z) < abs(target-res))
                {
                    res=z;
                    //cout<<x<<" "<<y<<" "<<z<<endl;
                }
                    
                else if(abs(target-z) == abs(target-res) and z< res)
                {
                    res=z;
                    //cout<<x<<" "<<y<<" "<<z<<endl;
                }
                    
            }
                
            
        }
        return res;
        
    }
};