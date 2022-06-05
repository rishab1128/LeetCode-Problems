class Solution {
public:
    int minMaxGame(vector<int>& arr) 
    {
        while(arr.size()>1)
        {
            vector<int>tmp;
            int k=0;
            for(int i=0; i<(int)arr.size(); i+=2){
                if(k%2==0)
                    tmp.push_back(min(arr[i],arr[i+1]));
                else
                    tmp.push_back(max(arr[i],arr[i+1]));
                k++;
            }
            arr = tmp;
        }
        return arr[0];
        
    }
};