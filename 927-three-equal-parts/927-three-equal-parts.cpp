using ll = long long;
class Solution {
public:
    
    string removeLeadingZeros(string s)
    {
        int i=0;
        for(i=0; i<s.size(); i++)
        {
            if(s[i]=='1')
                break;
        }
        string ans = s.substr(i);
        return ans;
    }
    
    bool check(vector<int>&arr, int left, int right)
    {
        string s="";
        for(auto x: arr)
            s+=to_string(x);
        
        string s1 = s.substr(0,left+1);
        string s2 = s.substr(left+1,right-left-1);
        string s3 = s.substr(right);
        
        string newS1 = removeLeadingZeros(s1);
        string newS2 = removeLeadingZeros(s2);
        string newS3 = removeLeadingZeros(s3);
        
        if(newS1 == newS2 and newS1 == newS3)
            return true;
        
        return false;
    }
    vector<int> threeEqualParts(vector<int>& arr) 
    {
        int n = arr.size() , ones = 0;
        for(auto x: arr)
        {
            if(x==1)
                ones++;
        }
        if(ones==0)
            return {0,n-1};
        if(ones%3)
            return {-1,-1};
        
        
        vector<int>pref(n,0),suff(n,0);
        
        if(arr[0])
            pref[0]=1;
        for(int i=1; i<n; i++)
        {
            if(arr[i])
                pref[i]=pref[i-1]+1;
            else
                pref[i]=pref[i-1];
        }
        
        if(arr[n-1])
            suff[n-1]=1;
        for(int i=n-2; i>=0; i--)
        {
            if(arr[i])
                suff[i]=suff[i+1]+1;
            else
                suff[i]=suff[i+1];
        }
        
//         for(auto x: pref)
//             cout<<x<<" ";
//         cout<<endl;
        
//         for(auto x: suff)
//             cout<<x<<" ";
//         cout<<endl;
        
//         cout<<n<<endl;
        
        int left = 0, right = n-1;
        while(left+1<right)
        {
            if(pref[left]<suff[right])
                left++;
            else if(suff[right]<pref[left])
                right--;
            else if(pref[left]==suff[right] and pref[left]==ones/3)
                break;
            else if(pref[left]==suff[right])
                left++, right--;   
        }
        
        // cout<<left<<" "<<right<<endl;
        
        int lastZeros = 0;
        for(int i=n-1; i>=0; i--)
        {
            if(arr[i])
                break;
            lastZeros++;
        }
        
        int zerosAfterLeft = 0;
        for(int i=left+1; i<n; i++)
        {
            if(arr[i])
                break;
            zerosAfterLeft++;
        }
        
        int zerosBeforeRight = 0;
        for(int i=right-1; i>=0; i--)
        {
            if(arr[i])
                break;
            zerosBeforeRight++;
        }
        
        if(zerosAfterLeft>=lastZeros and zerosBeforeRight>=lastZeros)
        {
            left+=lastZeros;
            right-=zerosBeforeRight-lastZeros;
            // cout<<left<<" "<<right<<endl;
            if(check(arr,left,right))
                return {left,right};
            return {-1,-1};
        }
        
        return {-1,-1};
        
    }
};