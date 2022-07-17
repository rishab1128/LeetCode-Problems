class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& arr, vector<vector<int>>& quer) 
    {
        //Preprocessing --> TC : O(n^2*log(n))
        
        int len = arr[0].size();
        vector<vector<pair<string,int>>>res;
        for(int i=0; i<len; i++)
        {
            vector<pair<string,int>>tmp;
            for(int j=0; j<arr.size(); j++)
            {
                // string num = arr[j];
                // string t = num.substr(i);
                tmp.push_back({arr[j].substr(i),j});
            }
            res.push_back(tmp);
        }
        
        for(auto &vec : res)
            sort(vec.begin(),vec.end());
        
        /*for(auto vec : res)
        {
            for(auto [x,y] : vec)
                cout<<x<<" "<<y<<"   ";
            cout<<endl;
        }*/
        
        vector<int>sol;
        for(auto vec : quer)
        {
            int k = vec[0] , trimmed = len-vec[1];
            int ans = res[trimmed][k-1].second;
            sol.push_back(ans);
        }
        
        
        return sol;
        
        
    }
};