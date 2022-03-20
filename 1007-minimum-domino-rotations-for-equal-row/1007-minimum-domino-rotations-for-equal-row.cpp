class Solution {
public:
    int minDominoRotations(vector<int>& arr1, vector<int>& arr2) 
    {
        int n=arr1.size();
        map<int,int>mp , A , B;
        for(int i=0; i<n; i++)
        {
            if(arr1[i]==arr2[i])
                mp[arr1[i]]++;
            else
            {
                mp[arr1[i]]++;
                mp[arr2[i]]++;
            }
            A[arr1[i]]++;
            B[arr2[i]]++;
        }
        
        vector<int>tmp;
        for(auto [ele , freq] : mp){
            if(freq>=n){
                tmp.push_back(ele);
            }
        }
        
        int ans=INT_MAX;
        for(auto x: tmp){
            int freqA = A[x] , freqB = B[x];
            int nA = n - freqA , nB = n - freqB;
            ans=min({ans,nA,nB});
        }
        
        return ans==INT_MAX ? -1 :  ans;
        
    }
};