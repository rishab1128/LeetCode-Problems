class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
        int n=deck.size();
        deque<int>dq;
        sort(deck.begin(),deck.end(),greater<int>());
        dq.push_front(deck[0]);
        for(int i=1; i<n; i++)
        {
            int x=dq.back();
            dq.pop_back();
            dq.push_front(x);
            dq.push_front(deck[i]);
        }
        vector<int>ans;
        while(dq.size()>0)
            ans.push_back(dq.front()),dq.pop_front();
        return ans;
    }
};