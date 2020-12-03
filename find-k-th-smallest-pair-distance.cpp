#include<bits/stdc++.h>
using namespace std;
​
//V.V.IMP QUES-->REFER CODECHEF-FANNG-SERIES-YOUTUBE
​
//Approach : Binary-Search + 2-Pointer
//TC: N*Log(N)(For Sorting) + N*Log(A[i])(BS+2-Pointer);
​
//Search-space =[0,1000000];
//low=0,high=10^6,mid=(low+high)/2;
​
//mid can be one of my possible answer if and only if the no. of pairs whose dis <= mid is >=k;
​
//Now,for a particular mid we will find the count of pairs whose distance <=mid , if ct>=k we will move to left for a more small ans and if ct<k we will traverse right
​
//Now , for a particular mid how will we find the count of the no. of pairs whose distance <=mid -->Using 2-pointer approach
​
//So, the idea is i=0,j=0, for every nums[j] we will find the smallest i such that a[j]-a[i]<=mid and the difference b/w j & i will give the no. of pairs for that j whose dis<=mid i.e. count+=j-i  do this for every j for a particular mid
​
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long low=0,high=5000000,ans=1000005;
        while(low<=high)
        {
            long long mid=low+((high-low)/2);
            int i=0,ct=0;
            for(int j=0; j<n; j++)
            {
                while(nums[j]-nums[i]>mid)
                    i++;
                ct+=(j-i);
            }
            //ct decides whether to go left or right
            if(ct>=k)
            {
                high=mid-1;
                ans=min(ans,mid);
            }
            else
                low=mid+1;
        }
​
        return ans;
    }
};
