using ll = long long;
class Solution {
public:
    ll merge(vector<int>&arr, ll left, ll right)
    {
        ll mid = (left+right)/2;
        ll y = mid+1 , cnt = 0;
        for(ll x=left; x<=mid; x++)
        {
            while(y<=right and arr[x] > 2LL*arr[y]){
                y++;
            }
            cnt += (y-(mid+1));
        }

        //Normal 2-poller Technique used in Merge Sort

        ll i = left , j = mid+1;
        vector<ll>tmp;

        while(i<=mid and j<=right)
        {
            if(arr[i]<arr[j])
                tmp.push_back(arr[i++]);

            else
                tmp.push_back(arr[j++]);
        }

        while(i<=mid){
            tmp.push_back(arr[i++]);
        }

        while(j<=right){
            tmp.push_back(arr[j++]);
        }

        ll k = 0;
        for(ll i=left; i<=right; i++){
            arr[i]=tmp[k++];
            // cout<<arr[i]<<" ";
        }


        return cnt;

    }

    ll mergeSort(vector<int>&arr, ll low, ll high)
    {
        if(low>=high)
            return 0;

        ll mid = (low+high)/2;

        ll leftCt = mergeSort(arr,low,mid);
        ll rightCt = mergeSort(arr,mid+1,high);
        ll mainCt = merge(arr,low,high);

        ll ans = leftCt+rightCt+mainCt;
        return ans;
    }


    int reversePairs(vector<int>& arr) 
    {
        ll n = arr.size();
        return mergeSort(arr,0ll,n-1ll);
    }
};