class Solution {
public:
    int largestCombination(vector<int>& arr) 
    {
        vector<int>freq(32,0);
        for(auto x: arr){
            for(int j=0; j<32; j++){
                int check = x&(1<<j);
                if(check)
                    freq[j]++;
            }
        }
        int ans=0;
        for(auto x: freq)
            ans=max(ans,x);
        
        return ans;
        
    }
};