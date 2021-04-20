class Solution {
public:
    int maxIceCream(vector<int>& cost, int coins) 
    {
        int n=cost.size();
        sort(cost.begin(),cost.end());
        int sum=0,ct=0;
        for(int i=0; i<n; i++)
        {
            if(sum+cost[i]<=coins)
            {
                sum+=cost[i];
                ct++;
            }
            else
                break;
        }
        cout<<ct<<endl;
        return ct;
        
    }
};