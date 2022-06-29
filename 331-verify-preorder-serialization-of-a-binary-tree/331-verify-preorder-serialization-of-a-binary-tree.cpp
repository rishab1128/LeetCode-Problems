class Solution {
public:
    bool isValidSerialization(string preorder) 
    {
        vector<int> arr;
        string s = "";
        for(auto &x : preorder)
        {
            if(x==',')
            {
                if(s == "#")
                    arr.push_back(-1);
                else
                    arr.push_back(stoi(s));
                s = "";
            }
            else
                s+=x;
        }
        
        if(s == "#")
            arr.push_back(-1);
        else
            arr.push_back(stoi(s));
        
        int m = arr.size();
        if(arr[m-1]!=-1)
            return false;
        
        stack<int>st;
        for(int i=0; i<m-1; i++)
        {
            if(arr[i]!=-1)
                st.push(arr[i]);
            else
            {
                if(st.empty())
                    return false;
                st.pop();
            }
        }
        
        return st.size()==0;
        
    }
};