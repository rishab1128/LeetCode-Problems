class Solution {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        vector<string> result;
        void dfs(string vtex)
        {
            auto & edges = graph[vtex];
            while (!edges.empty())
            {
                string to_vtex = edges.top();
                edges.pop();
                dfs(to_vtex);
            }
            result.push_back(vtex);
        }
    public:
        vector<string> findItinerary(vector<vector<string>>tickets) 
        {
            graph.clear();
            result.clear();
            int n=tickets.size();
            for (int i=0; i<n; i++)
                graph[tickets[i][0]].push(tickets[i][1]);
            dfs("JFK");
            reverse(result.begin(), result.end());
            return result;
        }
    };