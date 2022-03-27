class Solution {
public:
    int minDeletion(vector<int>&arr) 
    {
        int n=arr.size();
        int cnt0=1 , idx=0;
        for(int t=0; t<n-1; t++){
            if(t%2==0 and arr[t]==arr[t+1]){
                idx=t;
                break;
            }
        }
        int i = idx+1;
        while(i<n and arr[i]==arr[idx]){
            i++;
            cnt0++;
        }
        int t=0;
        t+=(cnt0-1);
        for(int j=i; j<n; j++){
            int cnt=1;
            int k=j+1;
            while(k<n and arr[j]==arr[k]){
                k++;
                cnt++;
            }
            
            if((j-t)%2){
                if(cnt>=2)
                    t+=(cnt-2);
            }
            else{
                t+=(cnt-1);
            }
            
            j=k-1;
        }
        int rem1 = n%2 , rem2 = t%2;
        if(rem1 ^ rem2 == 0 )
            return t;
        
        return t+1;
    }
};