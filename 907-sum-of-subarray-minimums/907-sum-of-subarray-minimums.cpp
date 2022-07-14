using ll = long long;
const int mod = 1e9+7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int>rightNse(n),leftNse(n);
        
        //right
        rightNse[n-1]=n;
        for(int i=n-2; i>=0; i--)
        {
            int j = i+1;
            while(j<n and arr[j]>arr[i])
                j = rightNse[j];
            rightNse[i] = j;
        }
        
        //left
        leftNse[0]=-1;
        for(int i=1; i<n; i++)
        {
            int j = i-1;
            while(j>=0 and arr[j]>=arr[i])
                j = leftNse[j];
            leftNse[i] = j;
        }
        
        /*for(auto x: leftNse)
            cout<<x<<" ";
        cout<<endl;
        
        for(auto x: rightNse)
            cout<<x<<" ";
        cout<<endl<<endl;*/
        
        ll ans = 0;
        for(int i=0; i<n; i++)
        {
            int rightIdx = rightNse[i];
            int leftIdx = leftNse[i];
            ll d = (rightIdx-i)*(i-leftIdx);
            ans += (d*arr[i]);
            ans %= mod;
            // cout<<d1<<" "<<d2<<" "<<d3<<endl;
        }
        
        return ans;
    }
};