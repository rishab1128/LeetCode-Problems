const int SIZE = 1000001;
class Solution {
public:
    int minimumCardPickup(vector<int>& arr) 
    {
        int n = arr.size() , i = 0 , ans = INT_MAX;
        vector<int>mp(SIZE,0);
        for(int j=0; j<n; j++)
        {
            if(!mp[arr[j]])
                mp[arr[j]]++;
            else
            {
                while(mp[arr[j]]==1)
                {
                    mp[arr[i]]--;
                    i++;
                }
                mp[arr[j]]++;
                ans = min(ans,j-i+2);
            }
        }
        return  ans==INT_MAX ? -1 : ans;
    }
};