#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    vector<bool> canEat(vector<int>& cand, vector<vector<int>>& que) 
    {
        int n=cand.size(),q=que.size();
        long long type,day,atmost;
        vector<bool>ans;
        long long pref[n];
        pref[0]=cand[0];
        for(long long i=1; i<n; i++)
            pref[i]=cand[i]+pref[i-1];
        for(int i=0; i<q; i++)
        {
            type=que[i][0];
            day=que[i][1];
            atmost=que[i][2];
            
            //Check - 1)If we have enough days to finish all pref[i-1] candies given that we                         consume 'atmost' amt. of candies per day.
            //        2)If we have enough no. of candies to last till day+1 days given that                         we consume 1 candie per day for 'day+1' days .
            if((day+1)*atmost>(type==0?0:pref[type-1])&&pref[type]>=(day+1)*1)
                ans.push_back(1);
            else
                ans.push_back(0);
            
        }
        return ans;
    }
};