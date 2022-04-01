class Solution {
public:
    vector<int> constructArray(int n, int k) 
    {
        vector<int>arr(n);
        if(k==1){
            for(int i=0; i<n; i++)
                arr[i]=i+1;
            return arr;
        }
        else if(k==2){
            arr[0]=1;
            arr[1]=3;
            arr[2]=2;
            for(int i=3; i<n; i++){
                arr[i]=i+1;
            }
            return arr;
        }
        int x=1 , y=n;
        for(int i=0; i<k; i++){
            if(i%2==0)
                arr[i]=x++;
            else
                arr[i]=y--;
        }
        if(abs(arr[k-1]-x)==1){
            for(int i=k; i<n; i++)
                arr[i]=x++;
        }
        else if(abs(arr[k-1]-y)==1){
            for(int i=k; i<n; i++)
                arr[i]=y--;
        }
        return arr;
    }
};