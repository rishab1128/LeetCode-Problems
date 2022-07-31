class NumArray {
public:
    void buildTree(vector<int>&arr, int*tree, int start, int end, int treeNode)
    {
        if(start==end)
        {
            tree[treeNode]=arr[start];
            return;
        }

        int mid=(start+end)/2;

        buildTree(arr,tree,start,mid,2*treeNode);
        buildTree(arr,tree,mid+1,end,2*treeNode+1);

        tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
    }

    void updateTree(vector<int>&arr, int*tree, int start, int end, int treeNode, int index, int value)
    {
        if(start==end)
        {
            tree[treeNode]=value;
            arr[index]=value;
            return;
        }

        int mid=(start+end)/2;
        if(index>mid)
        {
            updateTree(arr,tree,mid+1,end,2*treeNode+1,index,value);
        }
        else
        {
            updateTree(arr,tree,start,mid,2*treeNode,index,value);
        }

        tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
    }

    int query(int*tree,int start, int end, int treeNode, int left, int right)
    {
        //Completely outside given range
        if(start>right||end<left)
            return 0;

        //Completely inside given range
        if(start>=left&&end<=right)
            return tree[treeNode];

        //Partially inside and partially outside
        int mid=(start+end)/2;

        int ans1=query(tree,start,mid,2*treeNode,left,right); //Going Left
        int ans2=query(tree,mid+1,end,2*treeNode+1,left,right);//Going right

        return ans1+ans2;
    }
    
    int*tree=new int[120001];
    int n;
    vector<int>arr;
    NumArray(vector<int>& nums) 
    {
        n=nums.size();
        arr=nums;
        buildTree(arr,tree,0,n-1,1);
    }
    
    void update(int index, int val) 
    {
        updateTree(arr,tree,0,n-1,1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(tree,0,n-1,1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */