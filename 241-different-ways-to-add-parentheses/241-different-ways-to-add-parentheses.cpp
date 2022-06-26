class Solution {
public:
    
    vector<int> recur(string expr)
    {
        int n = expr.size();
        int i;
        char op='#';
        vector<int>res;
        
        for(i=0; i<n; i++)
        {
            if(expr[i]=='*' || expr[i]=='+' || expr[i]=='-'){
                op=expr[i];
                string s1 = expr.substr(0,i);
                string s2 = expr.substr(i+1);
                vector<int>left = recur(s1);
                vector<int>right = recur(s2);
                for(auto x: left)
                {
                    for(auto y: right){
                        if(op=='+')
                            res.push_back(x+y);
                        else if(op=='-')
                            res.push_back(x-y);
                        else
                            res.push_back(x*y);
                    }

                }
            }
        }
        
        if(op=='#')
        {
            return {stoi(expr)};
        }
    
        return res;
    }
    
    vector<int> diffWaysToCompute(string expr) 
    {
        int n = expr.size();
        return recur(expr);
    }
};