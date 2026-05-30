class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for(const auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);

        } 

        int ans = 0;
        set<int> seen;

        function<void(int)> dfs = [&](int node){
            seen.insert(node);
            for(auto neighbor : graph[node]){
                if(!seen.count(neighbor)){
                    dfs(neighbor);
                }
            }
        };

        for(int i = 0; i<n; i++){
            if(!seen.count(i)){
                ans++;
                dfs(i);
            }
        }
        return ans;
    }
};
