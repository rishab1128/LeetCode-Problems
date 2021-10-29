class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W)
    {
        map<int, int> mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        while(mp.size()>0){
            int minVal = mp.begin()->first;
            for(int i=minVal;i<minVal+W;i++){
                if(mp.find(i)==mp.end())
                    return false;
                int op = mp.find(i)->second;
                if(op == 1)
                    mp.erase(i);
                else
                    mp[i] = op-1;
            }
        }
        return true;
        
    }
};