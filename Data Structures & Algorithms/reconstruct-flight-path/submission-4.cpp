class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;

        set<pair<string, string>> processed;
        for(const auto& v : tickets){
            graph[v[0]].push(v[1]);
        }

        vector<string> path = {};

        function<void(string)> dfs = [&](const string& port){
            auto &pq = graph[port];
            while(!pq.empty()){
                string next = pq.top();
                pq.pop();
                dfs(next);
            }
            path.push_back(port);
        };
        string start = "JFK";
        dfs(start);
        reverse(path.begin(), path.end());
        return path;
    }
};
