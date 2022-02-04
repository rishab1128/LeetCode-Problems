class Solution {
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        unordered_map<int,int>mp;
        for(auto x: arr)
            mp[x%k]++;
        
//         for(auto [x,y] : mp)
//             cout<<x<<" "<<y<<endl;
        
//         cout<<endl;
        
        int n=arr.size() , count=0;
        for(auto x: arr)
        {
            if(mp.find(x%k)!=mp.end())
            {
                int check=(k-x%k)%k;
                int check2=-1*(k-check);
                
                if(mp.find(check)!=mp.end())
                {
                    // cout<<"X = "<<x<<" "<<"Check = "<<check<<endl;
                    if(check==x%k)
                    {
                        if(mp[check]>=2){
                            mp[check]-=2;
                            count++;
                        }
                    }
                    else
                    {
                        mp[check]--;
                        mp[x%k]--;
                        count++;
                    }
                    
                    if(mp[check]==0)
                        mp.erase(check);
                    if(mp[x%k]==0)
                        mp.erase(x%k);
                }
                else if(mp.find(check2)!=mp.end())
                {
                    // cout<<"X = "<<x<<" "<<"Check2 = "<<check2<<endl;
                    
                    if(check2==x%k)
                    {
                        if(mp[check2]>=2){
                            mp[check2]-=2;
                            count++;
                        }
                    }
                    else
                    {
                        mp[check2]--;
                        mp[x%k]--;
                        count++;
                    }
                    
                    if(mp[check2]==0)
                        mp.erase(check2);
                    if(mp[x%k]==0)
                        mp.erase(x%k);
                }
                
            }
        }
        
        return count==n/2;
        
    }
};