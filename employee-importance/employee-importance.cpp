/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
const int Size=2001;
class Solution {
public:
    vector<int>adj[Size];
    map<int,int>mp;
    
    void dfs(int id,int&ans)
    {
        ans+=mp[id];
        for(auto child: adj[id])
        {
            dfs(child,ans);
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) 
    {
        for(int i=0; i<Size; i++)adj[i].clear();
        mp.clear();
        
        
        for(int i=0; i<employees.size(); i++)
        {
            int id=employees[i]->id;
            int imp=employees[i]->importance;
            mp[id]=imp;
            vector<int>arr=employees[i]->subordinates;
            for(auto x: arr)
                adj[id].push_back(x);
        }
        
        int ans=0;
        dfs(id,ans);
        return ans;
        
    }
};