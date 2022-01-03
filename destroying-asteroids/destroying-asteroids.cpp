class Solution {
public:
    bool asteroidsDestroyed(int given_mass, vector<int>& arr) 
    {
        long long mass=given_mass;
        multiset<long long>st;
        for(auto x: arr)
            st.insert(x);
        
        while(!st.empty())
        {
            auto it=st.upper_bound(mass);
            if(it==st.begin())
                return 0;
            it--;
            mass+=(*it);
            st.erase(it);
        }
        
        return 1;
        
    }
};