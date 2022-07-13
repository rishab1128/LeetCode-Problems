/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    
    bool isCelebrity(int i , int n)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
                continue;
            if(knows(i,j) || !knows(j,i))
                return false;
        }
        return true;
    }
    
    int findCelebrity(int n) 
    {
        int celebrityCandidate = 0;
        for(int i=1; i<n; i++)
        {
            if(knows(celebrityCandidate , i))
                celebrityCandidate = i;
        }
        if(isCelebrity(celebrityCandidate,n))
            return celebrityCandidate;
        return -1;
    }
};