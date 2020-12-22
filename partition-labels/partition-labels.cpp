                x.SS.SS=x.SS.FF;
            arr.push_back(make_pair(x.SS.FF-1,x.SS.SS-1));
        }
        sort(all(arr));
        arr.push_back(make_pair(1000,1000));
        // for(auto x: arr)
        //  cout<<x.FF<<" "<<x.SS<<endl;
        //cout<<endl<<endl;
        int start=0,end=arr[0].SS,ans=0;
        vector<int>res;
        for(int i=1; i<(int)arr.size(); i++)
        {
            if(end<arr[i].FF)
            {
                ans=(end-start+1);
                res.push_back(ans);
                start=arr[i].FF;
                end=arr[i].SS;
            }
            else if(end>arr[i].FF&&end<arr[i].SS)
                end=arr[i].SS;
            else if(end>arr[i].FF&&end>arr[i].SS)
                continue;
        }
        // for(auto x: res)
        //  cout<<x<<" ";
        return res;
        
    }
};
​
