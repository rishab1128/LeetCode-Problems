class Solution {
public:
    
    static bool cmp(const vector<int>&a, const vector<int>&b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& arr) 
    {
        int n=arr.size();
        sort(arr.begin(),arr.end(),cmp);
        vector<int>tmp;
        tmp.push_back(arr[0][1]);
        for(int i=1; i<n; i++){
            if(arr[i][1]>tmp.back())
                tmp.push_back(arr[i][1]);
            else
            {
                int pos = lower_bound(tmp.begin(),tmp.end(),arr[i][1])-tmp.begin();
                tmp[pos] = arr[i][1];
            }
        }
        int ans = tmp.size();
        return ans;
        
    }
};