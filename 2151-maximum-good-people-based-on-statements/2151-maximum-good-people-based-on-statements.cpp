class Solution {
public:
    
    int n,ans;
    
    void dfs(vector<vector<int>>&states, int i, string& s, int ct)
    {
        if(i==n)
        {
            if(isValid(s,states))
                ans=max(ans,ct);
            return;
        }
        s.push_back('0'); //Assuming, i'th char is bad
        dfs(states,i+1,s,ct);
        s.back()='1'; //Assuming i'th char is good
        dfs(states,i+1,s,ct+1);
        s.pop_back();
    }
    
    bool isValid(string& s, vector<vector<int>>&states)
    {
        for(int i=0; i<n; i++)
        {
            if(s[i]=='1')
            {
                for(int j=0; j<n; j++)
                {
                    if(states[i][j]!=2 and states[i][j]!=s[j]-'0')
                        return false;
                }
            }
        }
        return true;
    }
    
    int maximumGood(vector<vector<int>>& states) 
    {
        ans=0;
        n=states.size();
        string s="";
        dfs(states,0,s,0);
        return ans;            
    }
};