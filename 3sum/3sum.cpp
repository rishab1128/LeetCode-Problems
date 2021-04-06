class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        map<vector<int>,int> m;
        for(int i=0;i<n-2;i++){
            int x=-v[i];
            int l=i+1,r=n-1;
            while(l<r)
            {
                
                if(v[l]+v[r]>x)r--;
                else if(v[l]+v[r]<x)l++;
                else 
                {
                    vector<int> c;
                    c.push_back(v[i]);c.push_back(v[l]);c.push_back(v[r]);
                    //sort(c.begin(),c.end());
                    m[c]++;
                    l++;r--;
                    while(l<r&&v[l]==c[1])
                        l++;
                    while(l<r&&v[r]==c[2])
                        r--;
                }
            }
            while(i<n-1&&v[i]==v[i+1])
                    i++;
        }
        vector<vector<int>> ans;
        for(auto x : m){
            ans.push_back(x.first);
        }
        return ans;
    }
};