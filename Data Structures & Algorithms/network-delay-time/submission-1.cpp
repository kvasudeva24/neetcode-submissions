class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> seen(n+1, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> graph;
        
        for ( const auto& e : times ) {
            graph[e[0]].push_back({e[1], e[2]});
        }

        seen[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while ( !pq.empty() ) {

            auto [elapsed, node] = pq.top();
            cout << "Explored: " << node << endl;
            pq.pop();

            for ( auto nbor : graph[node] ) {
                int nborNode = nbor.first;
                int weight = nbor.second;

                int nextTime = elapsed + weight;
                if ( seen[nborNode] == INT_MAX || nextTime < seen[nborNode] ) {
                    cout << "Updated " << nborNode << endl;
                    seen[nborNode] = nextTime;
                    pq.push({nextTime, nborNode});
                }
            }
            cout << "-" << endl;
        }

        int maxTime = -1;
        for ( int i = 1; i < seen.size(); i++ ) {
            if ( seen[i] == INT_MAX ) {
                cout << "Node " << i << " was never explored" << endl;
                return -1;
            } 
            maxTime = max(maxTime, seen[i]);
        }
        return maxTime;
    }
};
