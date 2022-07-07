class Solution {
public:
    int racecar(int target) {
        
        //This code also prints the required path;
        queue<pair<vector<int>,string>> q;
        q.push({{0, 0, 1},""}); //(moves,pos,velocity) , path;
        while (!q.empty()) 
        {
            
            vector<int> arr = q.front().first;
            string path = q.front().second;
            q.pop();
            
            
            int moves = arr[0];
            int pos = arr[1];
            int vel = arr[2];
            
            if (pos == target){
                cout<<path<<endl;
                return moves;
            } 
                
            
            
            if (abs(pos) > 2 * target) 
                continue;
            
            
            q.push({{moves + 1, pos + vel, 2 * vel} , path+"A"});
         
            
            if ((pos + vel > target && vel > 0) || (pos + vel < target && vel < 0)) {
                q.push({{moves + 1, pos, (vel > 0) ? -1 : 1},path+"R"});
            }
        }
        
        return 0;
    }
};