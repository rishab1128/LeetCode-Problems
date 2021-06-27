class Solution {
public:
    
    void merge(vector<pair<int,int>>&a, vector<int>&count , int start, int mid, int end)
    {
        int i=start,j=mid,k=0;
        vector<pair<int, int>>temp(end-start+1);
        int ct=0;

        while(i<mid&&j<=end)
        {
            if(a[i].first<=a[j].first)
            {
                temp[k]=a[i];
                count[a[i].second]+=ct;
                k++;
                i++;
            }
            else
            {
                ct++;
                temp[k]=a[j];
                k++;
                j++;
            }
        }

        while(i<mid)
        {
            temp[k]=a[i];
            count[a[i].second]+=ct;
            k++;
            i++;
        }

        while(j<=end)
        {
            temp[k]=a[j];
            k++;
            j++;
        }

        for(int i=start,k=0; i<=end; i++,k++)
        {
            a[i]=temp[k];
        }

    }

    void merge_sort(vector<pair<int,int>>&a, vector<int>&count , int start, int end)
    {
        
        if(start<end)
        {

           int mid=(start+end)/2;
           merge_sort(a,count,start,mid);
           merge_sort(a,count,mid+1,end);
           merge(a,count,start,mid+1,end);
        }

    }
    
    vector<int> countSmaller(vector<int>& a)
    {
        int n=a.size();
        vector<pair<int,int>>arr(n);
        for(int i=0; i<n; i++)
        {
          arr[i]={a[i],i};
        }

        vector<int>count(n,0);
        merge_sort(arr,count,0,n-1);

        return count;
        
    }
};