class Solution {
public:
    int minimumCardPickup(vector<int>& arr) 
    {
        int n = arr.size() , i = 0 , ans = INT_MAX;
        unordered_map<int,int>mp;
        for(int j=0; j<n; j++)
        {
            if(!mp.count(arr[j]))
                mp[arr[j]]++;
            else
            {
                while(mp[arr[j]]==1)
                {
                    mp[arr[i]]--;
                    if(mp[arr[i]]==0)
                        mp.erase(arr[i]);
                    i++;
                }
                mp[arr[j]]++;
                ans = min(ans,j-i+2);
            }
        }
        return  ans==INT_MAX ? -1 : ans;
    }
};