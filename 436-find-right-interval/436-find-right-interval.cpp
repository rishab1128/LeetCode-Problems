class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& arr) 
    {
        vector<pair<int,int>>tmp;
        for(int i=0; i<(int)arr.size(); i++)
            tmp.push_back({arr[i][0],i});
        
        sort(tmp.begin(),tmp.end());
        
        vector<int>tmp2;
        for(auto [x,y] : tmp)
            tmp2.push_back(x);
        
        int n=tmp2.size();
        vector<int>ans;
        for(auto v: arr)
        {
            int start = v[0] , end = v[1];
            int pos = lower_bound(tmp2.begin() , tmp2.end() , end)-tmp2.begin();
            if(pos==n)
                ans.push_back(-1);
            else
                ans.push_back(tmp[pos].second);
        }
        
        return ans;
        
    }
};