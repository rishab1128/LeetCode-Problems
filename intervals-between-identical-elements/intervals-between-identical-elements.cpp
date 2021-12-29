using ll=long long;
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) 
    {
        unordered_map<ll,vector<ll>>mp;
        unordered_map<ll,vector<long long>>pref;
        unordered_map<ll,vector<long long>>suff;
        
        ll n=arr.size();
        for(ll i=0; i<n; i++)
            mp[arr[i]].push_back(i);
        
        for(auto x: mp)
        {
            ll ele=x.first;
            pref[ele].push_back(mp[ele][0]);
            for(ll i=1; i<mp[ele].size(); i++)
                pref[ele].push_back(mp[ele][i]+pref[ele][i-1]);
        }
        
        for(auto x: mp)
        {
            ll ele=x.first;
            ll n=mp[ele].size();
            suff[ele].resize(n);
            suff[ele][n-1]=mp[ele][n-1];
            for(ll i=n-2; i>=0; i--)
                suff[ele][i]=mp[ele][i]+suff[ele][i+1];
        }
        
        /*for(auto x: mp)
        {
            cout<<x.first<<" -> ";
            for(auto ele : mp[x.first])
                cout<<ele<<" ";
            cout<<endl;
        }
        cout<<endl;
        
        for(auto x: pref)
        {
            cout<<x.first<<" -> ";
            for(auto ele : pref[x.first])
                cout<<ele<<" ";
            cout<<endl;
        }
        cout<<endl;
        
        for(auto x: suff)
        {
            cout<<x.first<<" -> ";
            for(auto ele : suff[x.first])
                cout<<ele<<" ";
            cout<<endl;
        }
        cout<<endl;*/
        
        long long sum=0;
        vector<long long>ans;
        
        for(ll i=0; i<n; i++)
        {
            ll ele=arr[i];
            ll idx=lower_bound(mp[ele].begin(),mp[ele].end(),i)-mp[ele].begin();
            ll n=mp[ele].size();
            sum=(i*idx)-(idx-1 >= 0 ? pref[ele][idx-1] : 0)+(idx+1<n ?  suff[ele][idx+1] : 0)-(i*(n-idx-1));
            ans.push_back(sum);
        }
        
        return ans;
    }
};