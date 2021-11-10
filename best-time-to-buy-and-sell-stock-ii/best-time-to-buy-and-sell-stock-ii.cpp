#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        std::ios::sync_with_stdio(false);
    }
    //Greedy Approach ; TC : O(N) ; SC: O(1)
    //For consecutive decreasing elements choose the last element which will be our buying day
    //For consecutive increasing elements choose the last element which will be our selling day
    //This will ensure that the sub-profits willbe as max as possible and also we can do multiple transactions
        
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size(), i=0;
        int maxProfit=0,buy=0,sell=0;
        while(i<n-1)
        {
            while(i+1<n&&prices[i+1]<=prices[i])i++;
            buy=prices[i];

            while(i+1<n&&prices[i+1]>prices[i])i++;
            sell=prices[i];

            maxProfit+=sell-buy;
        }
        return maxProfit;
    }
};


