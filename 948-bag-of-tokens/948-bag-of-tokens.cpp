class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) 
    {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int i=0,j=n-1,score=0;
        while(i<=j)
        {
            if(P>=tokens[i])
            {
                score++;
                P-=tokens[i];
                i++;
            }
            else if(P<tokens[i] and i<j)
            {
                if(score>=1)
                {
                    P+=tokens[j];
                    j--;
                    score--;
                }
                else
                    break;
            }
            else if(P<tokens[i] and i==j)
                break;
        }
        return score;
    }
};