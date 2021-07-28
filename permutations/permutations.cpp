class Solution {
public:
    vector<vector<int>>ans;
    void recur(vector<int>arr, vector<int>tmp , map<int,int>mp)
    {
        if(tmp.size()==arr.size())
        {
            ans.push_back(tmp);
            return;
        }
        for(int i=0; i<arr.size(); i++)
        {
            if(mp[arr[i]]==0)
            {
                tmp.push_back(arr[i]);
                mp[arr[i]]=1;
                recur(arr,tmp,mp);
                mp[arr[i]]=0;
                tmp.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& arr) 
    {
        ans.clear();
        map<int,int>mp;
        recur(arr,{},mp);
        return ans;
    }
};