class Solution {
public:
    int maxArea(vector<int>& ht) 
    {
        int n=ht.size();
        int start=0,end=n-1,area=0,ans=0;
        while(start<end)
        {
            area=min(ht[start],ht[end])*(end-start);
            ans=max(ans,area);
            if(ht[start]<=ht[end])
                start++;
            else 
                end--;
        }
        return ans;
        
    }
};