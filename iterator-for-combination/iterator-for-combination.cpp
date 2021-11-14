class CombinationIterator {
public:
    vector<string>arr;
    int pos;
    CombinationIterator(string chars, int combLen)
    {
        int n=chars.size();
        pos=0;
        arr.clear();
        for(int i=1; i<(1<<n); i++)
        {
            string s="";
            for(int j=0; j<n; j++)
            {
                if(i&(1<<j))
                    s+=chars[j];
            }
            if(s.size()==combLen)
                arr.push_back(s);
        }
        sort(arr.begin(),arr.end());
    }
    
    string next()
    {
        return arr[pos++];
    }
    
    bool hasNext()
    {
        if(pos==arr.size())
            return false;
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */