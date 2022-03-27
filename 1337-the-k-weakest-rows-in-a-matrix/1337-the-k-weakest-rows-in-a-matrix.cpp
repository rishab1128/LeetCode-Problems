#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector<pair<int,int>>v1;
        vector<int>ans;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0; i<m; i++)
        {
            sort(mat[i].begin(),mat[i].end());
            int pos=lower_bound(mat[i].begin(),mat[i].end(),1)-mat[i].begin();
            //cout<<pos<<endl;
            v1.push_back(make_pair(n-pos,i));
        }
        sort(v1.begin(),v1.end());
        for(int i=0; i<k; i++)
        {
            //cout<<v1[i].second<<" "<<v1[i].first<<endl;
            ans.push_back(v1[i].second);
        }
        return ans;
        
    }
};


