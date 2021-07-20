class Solution {
public:
    //Fisher Yates Algorithm for random shuffling
    //Time : O(N);
    vector<int>ori;
    Solution(vector<int>& nums) {
        ori=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ori;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() 
    {
        int n=ori.size();
        vector<int>shuffled=ori;
        int sizeLeft=n;
        for(int i=n-1; i>=0; i--)
        {
            int pos=rand()%sizeLeft;
            swap(shuffled[i],shuffled[pos]);
            sizeLeft--;
        }
        return shuffled;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */