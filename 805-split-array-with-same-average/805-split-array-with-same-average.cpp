class Solution {
public:
    bool splitArraySameAverage(vector<int>& arr) 
    {
        int n  = arr.size();
        int totalSum = accumulate(arr.begin(),arr.end(),0);
        
        vector<int>leftPart , rightPart;
        
        for(int i=0; i<n; i++)
        {
            if(i<n/2)
                leftPart.push_back(arr[i]);
            else
                rightPart.push_back(arr[i]);
        }
        
        int m1 = leftPart.size() , m2 = rightPart.size();
        
        map<int,vector<int>>subX , subY;
        
        for(int i=0; i<(1<<m1); i++)
        {
            int sz = 0 , subsetSum = 0;
            for(int j=0; j<m1; j++)
            {
                int num = (1<<j);
                if(i&num)
                {
                    sz++;
                    subsetSum+=leftPart[j];
                }
            }
            subX[sz].push_back(subsetSum);
        }
        
        for(int i=0; i<(1<<m2); i++)
        {
            int sz = 0 , subsetSum = 0;
            for(int j=0; j<m2; j++)
            {
                int num = (1<<j);
                if(i&num)
                {
                    sz++;
                    subsetSum+=rightPart[j];
                }
            }
            subY[sz].push_back(subsetSum);
        }
        
        /*for(auto &[sz,vec]: subX)
        {
            cout<<sz<<" -> ";
            for(auto &ele : vec)
                cout<<ele<<" ";
            cout<<endl;
        }
        
        cout<<endl;
        
        for(auto &[sz,vec]: subY)
        {
            cout<<sz<<" -> ";
            for(auto &ele : vec)
                cout<<ele<<" ";
            cout<<endl;
        }*/
        
        
        
        for(auto &[sz,vec] : subY)
            sort(vec.begin(),vec.end());
        
        
        for(int lenA=1; lenA<=n-1; lenA++)
        {
            
            for(int lenX=max(0,lenA-m2); lenX<=min(lenA,m1); lenX++)
            {
                int lenY = lenA - lenX;
                for(auto Sx : subX[lenX])
                {
                    int exp = totalSum*lenA - n*Sx;
                    if(exp%n==0)
                    {
                        int Sy = exp/n;
                        auto it = lower_bound(subY[lenY].begin(),subY[lenY].end(),Sy);
                        if((it!=subY[lenY].end()) and (*it)==Sy)
                            return true;
                    }
                }
            }
        }
        
        return false;
        
    }
};