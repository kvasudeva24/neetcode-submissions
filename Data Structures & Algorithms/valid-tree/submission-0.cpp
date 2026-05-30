class Solution {
public:
    map<int, vector<int>> graph;
    bool validTree(int n, vector<vector<int>>& edges) {
        for(const auto& v : edges){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }

        set<int> seen;
        if(hasCycle(0, -1, seen)) return false;

        return seen.size() == n;
    }

    bool hasCycle(int node, int parent, set<int>& seen){
        if(seen.count(node)) return true;
        seen.insert(node);

        for(const auto& nbor : graph[node]){
            if(nbor == parent) continue;
            if(hasCycle(nbor, node,seen)) return true;
        }

        return false;
    }
};
