bool cmp(const vector<int>&a , const vector<int>&b)
{
    if(a[0]==b[0])
        return a[1]<b[1];
    return a[0]<b[0];
}

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        int n=tasks.size();
        vector<vector<int>>arr(n);
        for(int i=0; i<n; i++)
            arr[i]={tasks[i][0] , tasks[i][1] , i};
        sort(arr.begin() , arr.end() , cmp);
        
        // for(auto v: arr)
        // {
        //     cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
        // }
        
        vector<int>ans;
        priority_queue< vector<int> , vector<vector<int>> , greater<> > readyQ;
        
        readyQ.push({arr[0][1] , arr[0][2]}); //processingTime , idx
        long long i=1 , last=arr[0][0];
        while(!readyQ.empty())
        {
            auto top=readyQ.top();
            readyQ.pop();
            int processingTime = top[0] , idx=top[1];
            last=last+processingTime;
            ans.push_back(idx);
            while(i<n)
            {
                if(arr[i][0] <= last)
                {
                    readyQ.push({arr[i][1] , arr[i][2]});
                    i++;
                }
                else
                    break;
            }
            if(readyQ.empty() and i<n)
            {
                readyQ.push({arr[i][1] , arr[i][2]});
                last=arr[i][0];
                i++;
            }     
        }
        
        return ans;
        
        
    }
};