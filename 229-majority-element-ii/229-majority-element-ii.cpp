class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) 
    {
        int n = arr.size();
        int cand1 = -1 , cand2 = -1 , ct1 = 0 , ct2 = 0;
        for(auto x : arr)
        {
            if(cand1!=-1 and cand1==x)
                ct1++;
            else if(cand2!=-1 and cand2==x)
                ct2++;
            else if(ct1==0)
            {
                cand1=x;
                ct1++;
            }
            else if(ct2==0)
            {
                cand2=x;
                ct2++;
            }
            else
            {
                ct1--;
                ct2--;
            }
        }
        
        ct1=0 , ct2=0;
        for(auto x: arr)
        {
            if(cand1==x)
                ct1++;
            else if(cand2==x)
                ct2++;
        }
        
        vector<int>ans;
        if(ct1>n/3)
            ans.push_back(cand1);
        if(ct2>n/3)
            ans.push_back(cand2);
        
        return ans;
        
    }
};