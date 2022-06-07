class Solution {
public:
    bool check(int i, int j, vector<int>&circle)
    {
        int x = circle[0] , y = circle[1], r=circle[2];
        return (x-i)*(x-i)+(y-j)*(y-j)<=r*r;
    }
    
    int countLatticePoints(vector<vector<int>>& arr) 
    {
        int n = arr.size() , cnt = 0;
        for(int i=0; i<=205; i++)
        {
            for(int j=0; j<=205; j++)
            {
                for(auto &circle : arr)
                {
                    if(check(i,j,circle)){
                        cnt++;
                        break;
                    }
                        
                }
            }
        }
        return cnt;
        
    }
};