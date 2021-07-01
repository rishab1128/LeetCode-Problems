class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) 
    {
        int n=arr.size();
        map<int,int>mp;
        for(int i=0; i<n; i++)
            mp[arr[i]]=i+1;
        
        vector<int>ans;
        for(int i=n; i>=1; i--)
        {
            if(arr[i-1]==i)
                continue;
            else
            {
                ans.push_back(mp[i]);
                ans.push_back(i);
                reverse(arr.begin(),arr.begin() + mp[i]) ;
                reverse(arr.begin(),arr.begin() + i) ;
                // for(auto x: arr)
                //     cout<<x<<" ";
                // cout<<endl;
                for(int i=0; i<n; i++)
                    mp[arr[i]]=i+1;
            }
            
        }
        return ans;
        
    }
};