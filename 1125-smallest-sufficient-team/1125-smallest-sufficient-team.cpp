class Solution {
public:
    
    map<int,int>mp;
    int m;
    
    //This func only calculates the min number of people reqd to complete all the skills
    int recur(int idx, int mask)
    {
        // cout<<idx<<" "<<mask<<endl;
        if(mask==(1<<m)-1)
            return 0;
        if(idx==mp.size())
            return INT_MAX;
        int op1 = recur(idx+1,mask|mp[idx])!=INT_MAX ? 1+recur(idx+1,mask|mp[idx]) : INT_MAX;
        int op2 = recur(idx+1,mask);
        return min(op1,op2);
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) 
    {
        mp.clear();
        m = req_skills.size();
        
        map<string,int>pos;
        unordered_map<int,vector<int>>dp;
        dp.reserve((1<<m));
        dp[0] = {};
        
        for(int i=0; i<m; i++)
        {
            string skill = req_skills[i];
            pos[skill] = i;
        }
        
        for(int i=0; i<people.size(); i++)
        {
            int num = 0;
            for(auto skill : people[i])
            {
                int idx = pos[skill];
                num+=(1<<idx);
            }
            
            //mp[i] = num;
            
            unordered_map<int,vector<int>>temp;
            temp = dp;
            for(auto [mask,vec] : dp)
            {
                int combMask = mask|num;
                if((temp.count(combMask) and temp[combMask].size()>dp[mask].size()+1) || (!temp.count(combMask)))
                    temp[combMask] = dp[mask] , temp[combMask].push_back(i);      
            }
            
            dp = temp;
            
            /*for(auto [mask,vec] : dp)
            {
                cout<<mask<<"-->";
                for(auto ele :  vec)
                    cout<<ele<<" ";
                cout<<endl;
            }
            cout<<endl;*/
        }
        
        // cout<<mp.size()<<endl;
        int ans = recur(0,0);
        cout<<ans<<endl;
        
        
        
        return dp[(1<<m)-1];
        
    }
};