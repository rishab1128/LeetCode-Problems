class Solution {
public:
    //Refer : https://leetcode.com/problems/furthest-building-you-can-reach/discuss/918374/Basic-Priority-Queue-Single-Pass-or-Code-with-Comments-or-Corner-Cases
    
    int furthestBuilding(vector<int>& hts, int bricks, int ladders) 
    {
        int n=hts.size();
        int totalBricksUsed=0 , i=0;
        priority_queue<int>bricksUsed;
        for(i=0; i<n-1; i++)
        {
            if(hts[i]>=hts[i+1])
                continue;
            else
            {
                int diff=hts[i+1]-hts[i];
                if(totalBricksUsed+diff<=bricks)
                {
                    totalBricksUsed+=diff;
                    bricksUsed.push(diff);
                }
                else if(totalBricksUsed+diff>bricks and ladders>0)
                {
                    if(bricksUsed.size()>0 and diff<bricksUsed.top() and totalBricksUsed-bricksUsed.top()+diff<=bricks)
                    {
                        totalBricksUsed=totalBricksUsed-bricksUsed.top()+diff;
                        bricksUsed.pop();
                        bricksUsed.push(diff);
                    }
                    ladders--;
                }
                else if(totalBricksUsed+diff>bricks and ladders==0)
                    break;
            }
        }
        
        return i;
        
    }
};