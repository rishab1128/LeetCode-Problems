using ll = long long;
class Solution {
public:
    
    //For each arr[i], find number of subarrays where arr[i] is minimum
    vector<ll>minSum(vector<int>&arr)
    {
        int n = arr.size();
        vector<ll>leftNse(n),rightNse(n); //leftNse[i] := stores the idx of left next smaller element w.r.t arr[i]
                                          //rightNse[i] := stores the idx of right next smaller element w.r.t arr[i]
        
        leftNse[0]=-1;
        for(int i=1; i<n; i++)
        {
            int j = i-1;
            while(j>=0 and arr[j]>=arr[i])
                j = leftNse[j];
            leftNse[i] = j;
        }
        
        rightNse[n-1]=n;
        for(int i=n-2; i>=0; i--)
        {
            int j = i+1;
            while(j<n and arr[j]>arr[i])
                j = rightNse[j];
            rightNse[i] = j;
        }
        
        vector<ll>ans(n);  //ans[i] := stores the number of subarrays where arr[i] is minimum
        for(int i=0; i<n; i++)
            ans[i] = (i-leftNse[i])*(rightNse[i]-i);
        
        return ans;
    }
    
    
    //For each arr[i], find number of subarrays where arr[i] is maximum
    vector<ll>maxSum(vector<int>&arr)
    {
        int n = arr.size();
        vector<ll>leftNge(n),rightNge(n); //leftNge[i] := stores the idx of left next greater element w.r.t arr[i]
                                          //rightNge[i] := stores the idx of right next greater element w.r.t arr[i]
        
        leftNge[0]=-1;
        for(int i=1; i<n; i++)
        {
            int j = i-1;
            while(j>=0 and arr[j]<=arr[i])
                j = leftNge[j];
            leftNge[i] = j;
        }
        
        rightNge[n-1]=n;
        for(int i=n-2; i>=0; i--)
        {
            int j = i+1;
            while(j<n and arr[j]<arr[i])
                j = rightNge[j];
            rightNge[i] = j;
        }
        
        vector<ll>ans(n);  //ans[i] := stores the number of subarrays where arr[i] is maximum
        for(int i=0; i<n; i++)
            ans[i] = (i-leftNge[i])*(rightNge[i]-i);
        
        return ans;
    }
    
    
    
    ll subArrayRanges(vector<int>& arr) 
    {
        //M -> Subarrays
        //Final ans  = (max1-min1)+(max2-min2)+(max3-min3)+...(maxM-minM)
        //           = (max1+max2+max3+..maxM)-(min1+min2+min3+...minM)
        //           = maxSum - minSum
        
        //[1,2,3]
        //Min = 1 --> [1] , [1,2] ,[1,2,3] --> Total contri of 1 in minSum = 3*1 ---> minSum += 1*3  --> minSum = 3
        //Min = 2 --> [2],[2,3] ---> Total contri of 2 in minSum = 2*2  ---> minSum += 2*2  --> minSum = 3+4 = 7
        //Min = 3 --> [3] ---> Total contri of 3 in minSum = 1*3 ---> minSum += 1*3 --> minSum = 7+3 = 10
        
        //Generalising, Let x = number of subarrays with arr[i] as minimum
        //Then, contri of arr[i] in minSum = arr[i]*x
        
        //The above same concept applies for maxSum as well...
        
        
        ll n  = arr.size();
        
        vector<ll>mini = minSum(arr); //mini[i] := stores the number of subarrays where arr[i] is minimum
        vector<ll>maxi = maxSum(arr); //maxi[i] := stores the number of subarrays where arr[i] is maximum
        
        
        ll maxiSum = 0 , miniSum = 0;
        for(int i=0; i<n; i++)
        {
            miniSum += arr[i]*mini[i];
            maxiSum += arr[i]*maxi[i];
        }
        
        ll ans = maxiSum - miniSum;
        return ans;
    }
};