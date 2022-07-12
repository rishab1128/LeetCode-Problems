class Solution {
public:
    string alienOrder(vector<string>& words) 
    {
        int n = words.size();
        vector<set<int>>adj(26);
        vector<int>indeg(26,0);
        unordered_set<int>present , finalSt;
        set<pair<int,int>>vis;
        
        for(auto word : words)
        {
            for(auto ch : word)
            {
                int ele = ch-'a';
                present.insert(ele);
            }
        }
        
        
        for(int i=0; i<n; i++)
        {
            string s1 = words[i];
            for(int j=i+1; j<n; j++)
            {
                string s2 = words[j];
                int k = 0;
                bool flag=1;
                for(k=0; k<min(s1.size(),s2.size()); k++)
                {
                    if(s1[k]==s2[k])
                        continue;
                    else
                    {
                        // cout<<s1<<" "<<s2<<" "<<s1[k]<<" "<<s2[k]<<endl;
                        int u = s1[k]-'a' , v = s2[k]-'a';
                        adj[u].insert(v);
                        if(!vis.count({u,v}))
                        {
                            vis.insert({u,v});
                            finalSt.insert(u);
                            finalSt.insert(v);
                            indeg[v]++;
                        }
                        flag=0;
                        break;
                    }
                }
                if(k!=s1.size() and flag) //For handling cases like ["abc" ,"ab"]
                    return "";
            }
        }
        
        queue<int>q;
        string ans = "";
        for(int i=0; i<26; i++)
        {
            if(!indeg[i] and finalSt.count(i))
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans+=node+'a';
            for(auto child : adj[node])
            {
                indeg[child]--;
                if(!indeg[child])
                    q.push(child);
            }
        }
        
        
        // cout<<ans.size()<<" "<<finalSt.size()<<endl;
        
        if(ans.size()!=finalSt.size())
            return "";
        
        unordered_set<int>st;
        for(auto x: ans)
            st.insert(x-'a');
        
        
        for(auto x: present)
        {
            if(!st.count(x) and !indeg[x])
                ans+=x+'a';
        }
        
        return ans;
        
        
    }
};