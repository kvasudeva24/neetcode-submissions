class Solution {
public:
    unordered_map<int, vector<pair<int,int>>> graph;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(const auto& t : times){
            graph[t[0]].push_back({t[1], t[2]});
        } 

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
        q.push({0, k});

        set<int> seen;
        int t = 0;

        while(!q.empty()){
            auto [cost, cur] = q.top();
            q.pop();


            if(seen.count(cur)) continue;
            seen.insert(cur);
            t = cost;
            for(auto [neighbor, weight] : graph[cur]){
                if(!seen.count(neighbor)){
                    q.push({t + weight,  neighbor});
                }
            }

        }
        return (seen.size() == n) ? t : -1;
    }
};
