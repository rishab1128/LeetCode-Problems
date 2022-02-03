class Solution {
public:
    int fourSumCount(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3, vector<int>& arr4)
    {
        int n=arr1.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int x=arr1[i]+arr2[j];
                mp[x]++;
            }
        }
        
        int ct=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int search=0-(arr3[i]+arr4[j]);
                if(mp.find(search)!=mp.end())
                    ct+=mp[search];
            }
        }
        
        return ct;
        
    }
};