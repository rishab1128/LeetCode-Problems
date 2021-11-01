class Solution {
public:
    int minimumOperations(vector<int>& arr, int start, int goal) 
    {
        queue<int>q;
        unordered_map<int,int>vis;
        q.push(start);
        int ct=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int x=q.front();
                q.pop();
                if(x==goal)
                    return ct;
                if(x<0 || x>1000 || vis[x])
                    continue;
                vis[x]=1;
                for(auto ele : arr)
                {
                    int num1=x+ele,num2=x-ele,num3=x^ele;
                    q.push(num1);
                    q.push(num2);
                    q.push(num3);
                }
                
            }
            if(q.size()>0)
                ct++;
        }
        
        return -1;
        
        
    }
};