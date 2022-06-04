class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int len) 
    {
        int n = tiles.size();
        sort(tiles.begin() , tiles.end());
        vector<int>pref(n+1) , endIdx(n);
        pref[0]=0;
        for(int i=1; i<=n; i++){
            pref[i]=pref[i-1]+(tiles[i-1][1]-tiles[i-1][0]+1);
            endIdx[i-1]=tiles[i-1][1];
        }
        
        // for(auto x: pref)
        //     cout<<x<<" ";
        // cout<<endl;
        // for(auto x: endIdx)
        //     cout<<x<<" ";
        // cout<<endl;
        
        int ans=0;
        for(int i=0; i<n; i++)
        {
            int start = tiles[i][0];
            int end = start+len-1;
            
            int idx = upper_bound(endIdx.begin(),endIdx.end(),end)-endIdx.begin();
            int sum = pref[idx]-pref[i];
            if(idx<n and end>=tiles[idx][0])
                sum+=end-tiles[idx][0]+1;
            
            // cout<<start<<" "<<end<<" "<<sum<<endl;
            
            ans=max(ans,sum);
        }
        
        return ans;
        
    }
};