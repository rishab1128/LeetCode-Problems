class Solution {
public:
    
    vector<int> tree;
    
    int build(vector<int>& arr,int start,int end,int i)
    {
        if(start==end)
            return tree[i]=start;
        else
        {
            int q=start+(end-start)/2;
            int left=build(arr,start,q,2*i+1);
            int right=build(arr,q+1,end,2*i+2);
            return tree[i]=arr[left]<arr[right]?left:right;
        }
    }
    
    int query(vector<int>& arr,int start,int end,int low,int high,int i)
    {
        if(start<=low&&end>=high)
            return tree[i];
        else if(high<start||end<low)
            return -1;
        else
        {
            int q=(high+low)/2;
            int left=query(arr,start,end,low,q,2*i+1);
            int right=query(arr,start,end,q+1,high,2*i+2);
            if(left==-1)
                return right;
            if(right==-1)
                return left;
            return arr[left]<arr[right]?left:right;
        }

    }
    
    int divideAndConquer(int subArrVal,int start,int end,vector<int>& target)
    {
        if(start<=end)
        {
            int q=query(target,start,end,0,target.size()-1,0);
            int val=target[q]-subArrVal;
            return val+divideAndConquer(target[q],start,q-1,target)+divideAndConquer(target[q],q+1,end,target);
        }
        else return 0;
    }
    
    int minNumberOperations(vector<int>& target) 
    {
        int n=target.size();
        tree.resize(4*n,-1);
        build(target,0,n-1,0);
        return divideAndConquer(0,0,n-1,target);
    }
};