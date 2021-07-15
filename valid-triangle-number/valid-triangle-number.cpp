class Solution {
public:
    int triangleNumber(vector<int>& arr) 
    {
        int n=arr.size();
        sort(arr.begin() , arr.end() );
        int ans=0;
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int pos=lower_bound(arr.begin()+j+1,arr.end(),arr[i]+arr[j])-arr.begin();
                ans+=(pos-j-1);
                //cout<<arr[i]<<" "<<arr[j]<<" "<<pos<<" "<<pos-j-1<<endl;
            }
        }
        //cout<<"-------------------------"<<endl;
        return ans;
        
    }
};