#include<bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
  
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

using ll=long long int;
using ld=long double;

class Solution {
public:
    
    
    long long goodTriplets(vector<int>& arr1, vector<int>& arr2) 
    {
        int n=arr1.size();
        unordered_map<int,int>m;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            m[arr1[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            v.push_back(m[arr2[i]]);
        }


        ordered_set s1,s2;
        vector<long long>left(n,0),right(n,0);
        s1.insert(v[0]);
        for(int i=1;i<n;i++)
        {
            left[i]=s1.order_of_key(v[i]);
            s1.insert(v[i]);
        }
        s2.insert(v[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            right[i]=(n-1-i)-s2.order_of_key(v[i]);
            s2.insert(v[i]);
        }

//         for(auto x: v)
//             cout<<x<<" ";
//         cout<<endl;

//         for(int i=0; i<n; i++){
//             cout<<left[i]<<" "<<right[i]<<endl;
//         }


        long long sum=0;
        for(int i=0;i<v.size();i++)
        {
            long long t=left[i]*right[i];
            sum+=t;
        }
        
        return sum;

        
        
    }
};