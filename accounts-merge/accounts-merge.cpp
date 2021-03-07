class Solution 
{
public:
    
    string find(string s, map<string, string>& p) 
    {
        return p[s] == s ? s : find(p[s], p);
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) 
    {
        map<string, string> owner;
        map<string, string> parents;
        map<string, set<string>> unions;
        
        for (int i = 0; i < acts.size(); i++) 
        {
            for (int j = 1; j < acts[i].size(); j++) 
            {
                parents[acts[i][j]] = acts[i][j];
                owner[acts[i][j]] = acts[i][0];
            }
        }
        
        
        for (int i = 0; i < acts.size(); i++) 
        {
            string p = find(acts[i][1],parents);
            //cout<<"P = "<<p<<endl;
            for (int j = 2; j < acts[i].size(); j++)
                parents[find(acts[i][j],parents)] = p;
            
            //for(auto x: parents)
            //cout<<x.first<<"------>"<<x.second<<endl;
            //cout<<"---------------------------------------"<<endl;
        }
        
        
        for (int i = 0; i < acts.size(); i++)
            for (int j = 1; j < acts[i].size(); j++)
                unions[find(acts[i][j], parents)].insert(acts[i][j]);
        
        /*for(auto x: unions)
        {
            cout<<x.first<<"--->";
            set<string>s=x.second;
            for(auto i: s)
                cout<<i<<" ";
            cout<<endl;
        }*/
            
        

        vector<vector<string>> res;
        for (pair<string, set<string>> p : unions) 
        {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }

};