class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) 
    {
        vector<int>pos,neg;
        for(auto x: arr)
        {
            if(x>0)
                pos.push_back(x);
            else
                neg.push_back(x);
        }
        
        vector<int>ans;
        int m=pos.size();
        int i=0,j=0,ct=0;
        while(ct<2*m)
        {
            if(ct%2==0)
                ans.push_back(pos[i++]);
            else
                ans.push_back(neg[j++]);
            ct++;
        }
        return ans;
        
    }
};