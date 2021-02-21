#define rsort(a)   sort(a.rbegin(), a.rend())
class Solution {
public:
    int minDeletions(string s) 
    {
        int n=s.size();
        map<char,int>mp;
        map<int,int>mp2;
        for(int i=0; i<n; i++)
        {
            mp[s[i]]++;
        }
       
        vector<int>arr;
        for(auto x: mp)
            arr.push_back(x.second);
        rsort(arr);
        for(auto x: arr)
        {
            //cout<<x<<" ";
            mp2[x]++;
        }
        // cout<<endl;
        // for(auto x: mp2)
        //     cout<<x.first<<" "<<x.second<<endl;
        int ct=0;
        for(int i=1; i<arr.size(); i++)
        {
            if(mp2[arr[i]]>1)
            {
                int tmp=arr[i];
                while(mp2[arr[i]]!=0)
                {
                    arr[i]--;
                    ct++;
                }
                mp2[tmp]--;
                if(arr[i]>0)
                    mp2[arr[i]]++;
            }
        }
            
        return ct;
    }
};