class Bitset {
public:
    vector<bool>bits;
    bool flips;
    int ct;
    
    Bitset(int size) {
        bits.resize(size,0);
        flips=0;
        ct=0;
    }
    
    void fix(int idx) {
        
        if((bits[idx]+flips)%2==0)
        {
            ct++;
            bits[idx]=!bits[idx];
        }
        
    }
    
    void unfix(int idx) {
        
        if((bits[idx]+flips)%2!=0)
        {
            ct--;
            bits[idx]=!bits[idx];
        }
    }
    
    void flip() {
        
        ct=bits.size()-ct;
        flips=!flips;
        
    }
    
    bool all() {
        
        return ct==bits.size();
    }
    
    bool one() {
        
        return ct>=1;
    }
    
    int count() {
        
        return ct;
    }
    
    string toString() {
        
        string ans="";
        for(auto bit : bits)
        {
            if((bit+flips)%2==0)
                ans+='0';
            else
                ans+='1';
        }
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */