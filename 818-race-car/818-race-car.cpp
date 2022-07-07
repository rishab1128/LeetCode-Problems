class Solution {
public:
    int racecar(int target) {
        
        queue<vector<int>> q;
        q.push({0, 0, 1}); //moves,pos,velocity;
        while (!q.empty()) {
            
            vector<int> arr = q.front();
            q.pop();
            
            
            int moves = arr[0];
            int pos = arr[1];
            int vel = arr[2];
            
            if (pos == target) 
                return moves;
            
            
            if (abs(pos) > 2 * target) 
                continue;
            
            
            q.push({moves + 1, pos + vel, 2 * vel});
         
            
            if ((pos + vel > target && vel > 0) || (pos + vel < target && vel < 0)) {
                q.push({moves + 1, pos, (vel > 0) ? -1 : 1});
            }
        }
        
        return 0;
    }
};