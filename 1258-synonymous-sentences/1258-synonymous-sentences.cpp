class Solution {
public:
    
    vector<string>  strToVec(string s)
    {
        vector<string>ans;
        stringstream ss(s);
        string word;
        while(ss>>word)
            ans.push_back(word);
        return ans;
    }
    
    string vecToStr(vector<string>v)
    {
        string ans = "";
        for(auto word :  v)
            ans+=word , ans+=" ";
        ans.pop_back();
        return ans;
    }
    
    vector<string> generateSentences(vector<vector<string>>& arr, string text) 
    {
        unordered_map<string,vector<string>>adj;
        
        for(auto vec :  arr)
        {
            string u = vec[0] , v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<string>q;
        q.push(text);
        set<string>ans;
        while(!q.empty())
        {
            string sen = q.front();
            q.pop();
            ans.insert(sen);
            
            vector<string>vec = strToVec(sen);
            for(int i=0; i<vec.size(); i++)
            {
                if(adj.count(vec[i]))
                {
                    for(auto neigh : adj[vec[i]])
                    {
                        vector<string>newVec = vec;
                        newVec[i] = neigh;
                        string res = vecToStr(newVec);
                        if(!ans.count(res))
                            q.push(res);
                    }
                }
            }
        }
        
        vector<string>res(ans.begin(),ans.end());
        return res;
    }
};