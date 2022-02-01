#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    Solution(){
        std::ios::sync_with_stdio(false);
    }

    int maxProfit(vector<int>& prices) 
    {
        //Greedy type approach
        int n=prices.size(),ans=0;
        int maxi[n]; //maxi[i]-->stores the largest no. b/w i to n-1
        maxi[n-1]=prices[n-1];
        for(int i=n-2; i>=0; i--)
        {
            if(prices[i]>maxi[i+1])
                maxi[i]=prices[i];
            else
                maxi[i]=maxi[i+1];
        }
        for(int i=0; i<n-1; i++)
        {
            int buy=prices[i];
            int sell=maxi[i+1];
            ans=max(ans,sell-buy);
        }
        return ans;
        
    }
};


