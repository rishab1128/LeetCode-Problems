class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        set<int>st1 , st2;
        for(auto x: nums1)
            st1.insert(x);
        for(auto x: nums2)
            st2.insert(x);
        
        vector<int>ans0 , ans1;
        for(auto x: st1){
            if(st2.find(x)==st2.end())
                ans0.push_back(x);
        }
        for(auto x: st2){
            if(st1.find(x)==st1.end())
                ans1.push_back(x);
        }
        return {ans0,ans1};
        
    }
};