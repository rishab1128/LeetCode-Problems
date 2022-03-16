class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int n=popped.size();
        int i = 0, j = 0;
        for (int x : pushed) {
            pushed[i++] = x;
            while (i > 0 && pushed[i - 1] == popped[j])
                --i, ++j;
        }
        return j==n;
    }
    
};