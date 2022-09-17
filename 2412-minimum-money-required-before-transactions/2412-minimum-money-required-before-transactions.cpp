using ll = long long;
class Solution {
public:
    ll minimumMoney(vector<vector<int>>& arr) 
    {
        int n = arr.size();
        vector<vector<int>>profit , loss;
        for(auto &v: arr)
        {
            int cost = v[0] , cashback = v[1];
            if(cashback>=cost)
                profit.push_back(v);
            else
                loss.push_back(v);
        }
        
        
        
        auto cmp1 = [&](vector<int>&v1 , vector<int>&v2){
            
            int cost1 = v1[0] , cashback1 = v1[1];
            int cost2 = v2[0] , cashback2 = v2[1];
            
            if(cost1==cost2)
                return cashback1 < cashback2;
            
            return cost1 > cost2;
            
        };
        
        auto cmp2 = [&](vector<int>&v1 , vector<int>&v2){
            
            int cost1 = v1[0] , cashback1 = v1[1];
            int cost2 = v2[0] , cashback2 = v2[1];
            
            if(cashback1 == cashback2)
                return cost1 > cost2;
            
            return cashback1 < cashback2;
            
        };
        
        if(profit.size())
            sort(profit.begin(),profit.end(),cmp1);
        if(loss.size())
            sort(loss.begin(),loss.end(),cmp2);
        
        /*
        
        for(auto &v: profit)
            cout<<v[0]<<" "<<v[1]<<endl;
        cout<<endl;
        
        for(auto &v: loss)
            cout<<v[0]<<" "<<v[1]<<endl;
        cout<<endl;
        
        */
        
        ll cost = 0 , cashback = 0;
        for(int i=0; i<(int)loss.size(); i++)
        {
            cost+=loss[i][0];
            if(i!=(int)loss.size()-1)
                cashback+=loss[i][1];
        }
        
        ll ans = cost-cashback;
        ll rem = ans;
        
        for(auto &v: loss)
        {
            int cost = v[0] , cashback = v[1];
            rem=rem-cost+cashback;    
        }
        
        // cout<<rem<<endl;
        
        if(profit.size())
        {
            if(rem>=profit[0][0])
                return ans;
            else
                return ans+abs(profit[0][0]-rem);
        }
        
        
        return ans;
        
    }
};