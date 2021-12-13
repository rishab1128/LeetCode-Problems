class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) 
    {
        int n=2e5+2;
        vector<int>right(n,0) , left(n,0);
        vector<int> amt(n, 0);
        for(auto& x : fruits) {
            amt[x[0]] = x[1]; 
        }
        
        int sum1=0 , sum2=0 , ans=amt[startPos];
        for(int i=startPos; i<n; i++)
        {
            sum1+=amt[i];
            right[i]=sum1;
        }
        for(int i=startPos; i>=0; i--)
        {
            sum2+=amt[i];
            left[i]=sum2;
        }
        
        
        //First left and then right
        for(int i=0; i<=min(k/2, startPos); i++) 
        { 
            int r = min(k-2*i, n-1-startPos); 
            if(startPos+r<n) {
                ans = max(ans, left[startPos-i] + right[startPos+r] - amt[startPos]);
            }
        }
        
        //First right and then left
        for(int i=0; i<=min(k/2, n-1-startPos); i++) 
        { 
            int l = min(k-2*i, startPos); 
            if(startPos-l>=0) {
                ans = max(ans, left[startPos-l] + right[startPos+i] - amt[startPos]);
            }
        }
        
        return ans;
        
    }
};