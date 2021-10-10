class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        vector<int>tmp;
        int rem=grid[0][0]%x;
        for(auto v: grid)
        {
            for(auto ele : v){
                tmp.push_back(ele);
                if(ele%x!=rem)
                    return -1;
            }
                
        }
        sort(tmp.begin(),tmp.end());
        int n=tmp.size();
        int req=tmp[n/2];
        int ops=0;
        for(auto ele: tmp)
        {
            ops+=(abs(ele-req)/x);
        }
        return ops;
        
    }
};