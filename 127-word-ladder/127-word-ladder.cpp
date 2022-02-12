class Solution {
public:
    int solve(vector<string>&dict, string start, string end) 
    {
        unordered_map<string,int>mp1,vis;
        for(auto x: dict)
            mp1[x]=1;
        queue<pair<string,int>>q;
        q.push({start,0});
        vis[start]=1;
        int ans=0;
        while(q.size()>0)
        {
            int sz=q.size();
            while(sz--)
            {
                string key=q.front().first;
                int steps=q.front().second;
                //cout<<key<<" "<<steps<<endl;
                q.pop();
                if(key==end)
                {
                    ans=steps;
                    break;
                }
                for(int i=0; i<key.size(); i++)
                {
                    string tmp=key;
                    for(char j='a' ; j<='z' ; j++)
                    {
                        tmp[i]=j;
                        if(vis[tmp]==0 and mp1[tmp]==1){
                            q.push({tmp,steps+1});
                            vis[tmp]=1;
                        }

                    }
                }
            }
        }
        
        if(ans==0)
            return 0;
        return ans+1;
    }
    
    int ladderLength(string start, string end, vector<string>& dict) 
    {
        return solve(dict,start,end);
    }
};