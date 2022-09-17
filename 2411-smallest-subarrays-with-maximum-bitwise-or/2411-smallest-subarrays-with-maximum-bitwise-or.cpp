class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> ans;
        vector<int> arr2(32, -1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 32; j++) {
                if (arr[i] & (1 << j))
                    arr2[j] = i;
            }

            int lsb = i;

            
            for (int j = 0; j < 32; j++)
                lsb = max(lsb, arr2[j]);

            ans.push_back(lsb - i + 1);
        }

        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};