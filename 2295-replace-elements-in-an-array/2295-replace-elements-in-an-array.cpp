class Solution {
public:
    vector<int> arrayChange(vector<int>& arr, vector<vector<int>>& ops) 
    {
        int n = arr.size() , m = ops.size();
        map<int,int>posToNum , numToPos;
        for(int i=0; i<n; i++){
            numToPos[arr[i]]=i;
            posToNum[i]=arr[i];
        }
        for(int i=0; i<m; i++)
        {
            int oldNum = ops[i][0] , newNum = ops[i][1];
            int idx = numToPos[oldNum];
            posToNum[idx] = newNum;
            numToPos.erase(oldNum);
            numToPos[newNum] = idx;
        }
        vector<int>ans(n);
        for(auto [idx , num] : posToNum)
            ans[idx] = num;
        
        return ans;
            
        
    }
};