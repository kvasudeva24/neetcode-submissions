class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> pq;
        vector<vector<int>> closest;

        for ( auto& point : points ) {
            int distance = (pow(point[0], 2)) + (pow(point[1], 2));
            if ( pq.size() < k ) {
                pq.push({distance, {point[0], point[1]}}); 
            } else if (distance < pq.top().first) {
                pq.pop();
                pq.push({distance, {point[0], point[1]}}); 
            }
        }

        for ( int i = 0; i < k; i++ ) {
            auto [_, v] = pq.top();
            pq.pop();
            closest.push_back({v.first, v.second});
        }
        return closest;
    }
};
