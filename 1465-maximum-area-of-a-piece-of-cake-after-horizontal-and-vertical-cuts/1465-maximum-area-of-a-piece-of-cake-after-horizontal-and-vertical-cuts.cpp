class Solution {
public:
    int maxArea(int h, int w, vector<int>& hori, vector<int>& vert) 
    {
        const int mod = 1e9+7;
        
        hori.push_back(0);
        hori.push_back(h);
        
        vert.push_back(0);
        vert.push_back(w);
        
        sort(hori.begin(),hori.end());
        sort(vert.begin(),vert.end());
        
        long long maxHori = 0 , maxVert = 0;
        for(int i=1; i<hori.size(); i++)
            maxHori = max(maxHori , (long long)hori[i]-hori[i-1]);
        
        for(int i=1; i<vert.size(); i++)
            maxVert = max(maxVert , (long long)vert[i]-vert[i-1]);
        
        long long ans = (maxHori*maxVert)%mod;
        return ans;
    }
};