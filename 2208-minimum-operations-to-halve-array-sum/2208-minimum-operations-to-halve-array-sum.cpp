using ll=long long;
class Solution {
public:
    int halveArray(vector<int>& arr) 
    {
        priority_queue<double>pq;
        double sum=0.0;
        ll ct=0;
        for(auto x: arr){
            pq.push((double)x);
            sum+=x;
        }
        double halfSum = ((double)sum)/2;
        double tot=sum , tmp=0.0;
        while(1)
        {
            double tp = pq.top();
            pq.pop();
            double halfTp = tp/2;
            tmp  = tmp + halfTp; 
            tot  = tot - tmp;
            // cout<<tp<<" "<<halfTp<<" " <<" "<<tmp<<" "<<sum<<" "<<tot<<" "<<sum-tot<<endl;
            if(sum - tot>=halfSum)
                break;
            pq.push(halfTp);
            tot=sum;
            ct++;
        }
        return ct+1;
    }
};