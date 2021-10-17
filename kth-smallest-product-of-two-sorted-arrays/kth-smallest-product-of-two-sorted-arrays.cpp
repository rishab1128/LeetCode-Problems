using ll=long long;
class Solution {
public:
    bool check(vector<int>&nums1 , vector<int>&nums2 , ll midVal , ll k)
    {
        ll n=nums1.size() , cnt=0;
        for(int i=0; i<n; i++)
        {
            ll val=nums1[i];
            
            if(val==0 and midVal>=0)
                cnt+=(int)nums2.size();
            
            else if(val>0)
                cnt+=findMaxIdx(nums2, val , midVal);
            
            else if(val<0)
                cnt+=findMinIdx(nums2, val , midVal);
            
            //cout<<cnt<<endl;
        }
        return cnt>=k;
    }
    
    int findMaxIdx(vector<int>&nums2 , ll val , ll midVal)
    {
        int low=0 , high=nums2.size()-1 , pos=-1;
        while(low<=high)
        {
            ll mid=(low+high)/2;
            if(nums2[mid]*val<=midVal)
            {
                pos=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return pos+1;
    }
    
    int findMinIdx(vector<int>&nums2 , ll val , ll midVal)
    {
        int low=0 , high=nums2.size()-1 , pos=nums2.size();
        while(low<=high)
        {
            ll mid=(low+high)/2;
            if(nums2[mid]*val<=midVal)
            {
                pos=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return (int)nums2.size()-pos;
    }
    
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) 
    {
        ll low=-1e10 , high=1e10 , ans=0;
        while(low<=high)
        {
            ll mid=(low+high)/2;
            if(check(nums1 , nums2 , mid , k))
            {
                //cout<<mid<<endl;
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};