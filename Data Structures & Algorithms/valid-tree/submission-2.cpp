class Solution {
public:
    unordered_map<int, vector<int>> graph;

    bool validTree(int n, vector<vector<int>>& edges) {
        if ( edges.size() != (n - 1)) return false;

        vector<bool> seen(n, false);
        for ( auto e : edges ) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        for ( int node = 0; node < n; node++ ) {
            if ( seen[node] == false ) {
                cout << "Start DFS @ Node: " << node << endl;
                seen[node] = true;
                bool cycle = false;
                hasCycle(node, -1, seen, cycle);
                if ( cycle ) { return false; } 
                cout << "-" << endl;
            }
        }
        return true;
    }

    void hasCycle(int node, int parent, vector<bool>& seen, bool& cycleDetected) {

        for ( int nbor : graph[node] ) {
            if ( nbor == parent ) { continue; }
            cout << "Node " << node << " has nbor " << nbor << endl;
            if ( seen[nbor] == false ) {
                seen[nbor] = true;
                hasCycle(nbor, node, seen, cycleDetected);
            } else {
                cout << "Cycle Detected at " << node << " and " << nbor << endl;
                cycleDetected = true;
            }
        }

    }
};
