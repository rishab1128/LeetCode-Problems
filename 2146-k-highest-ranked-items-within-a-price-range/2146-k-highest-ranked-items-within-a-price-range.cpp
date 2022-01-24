class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& A, vector<int>& P, vector<int>& start, int k) {
        int M = A.size(), N = A[0].size(), step = 0, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int, int>> q{{{start[0], start[1]}}};
        vector<vector<int>> dist(M, vector<int>(N, INT_MAX)), ans; // dist[x][y] is the shortest distance from (x,y) to `start`.
        dist[start[0]][start[1]] = 0;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y] = q.front();
                q.pop();
                if (A[x][y] >= P[0] && A[x][y] <= P[1]) ans.push_back({x, y});
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || b < 0 || a >= M || b >= N || A[a][b] == 0 || dist[a][b] != INT_MAX) continue;
                    dist[a][b] = step + 1;
                    q.emplace(a, b);
                }
            }
            ++step;
        }
        sort(begin(ans), end(ans), [&](auto &a, auto &b) {
            int x1 = a[0], y1 = a[1], x2 = b[0], y2 = b[1];
            int d1 = dist[x1][y1], d2 = dist[x2][y2];
            if (d1 != d2) return d1 < d2;
            int p1 = A[x1][y1], p2 = A[x2][y2];
            if (p1 != p2) return p1 < p2;
            return a < b;
        });
        if (ans.size() > k) ans.resize(k);
        return ans;
    }
};