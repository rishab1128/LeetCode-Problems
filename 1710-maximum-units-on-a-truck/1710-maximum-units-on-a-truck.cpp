bool cmp(const vector<int>&a, const vector<int>&b)
{
    return a[1]>b[1];
}

class Solution {
public:
    
    int maximumUnits(vector<vector<int>>& box, int truck) 
    {
        sort(box.begin() , box.end() , cmp);
        int n=box.size() , ans=0;
        for(int i=0; i<n; i++)
        {
            if(box[i][0]<=truck)
            {
                ans+=box[i][0]*box[i][1];
                truck-=box[i][0];
            }
            else
            {
                ans+=truck*box[i][1];
                break;
            }
                
        }
        return ans;
        
    }
};