class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int add) 
    {
        int n = cap.size();
        vector<int>diff(n);
        for(int i=0; i<n; i++)
            diff[i]=cap[i]-rocks[i];
        sort(diff.begin(),diff.end());
        int tot = add , ct=0;
        for(int i=0; i<n; i++){
            if(tot>=diff[i])
            {
                ct++;
                tot-=diff[i];
            }
            else
                break;
        }
        return ct;
        
    }
};