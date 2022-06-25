class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) 
    {
        int n = pos.size();
        
        vector<pair<int,int>>arr;
        for(int i=0; i<pos.size(); i++)
            arr.push_back({pos[i],speed[i]});
        
        sort(arr.rbegin(),arr.rend());
        
        double maxTimeTaken = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            double timeTaken = ((double)target - arr[i].first)/arr[i].second;
            if(timeTaken > maxTimeTaken)
            {
                maxTimeTaken = timeTaken;
                ans++;
            }
        }
        
        return ans;
        
        
    }
};