class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> redundant;
        int vertices = edges.size() - 1 + 1; 
        vector<int> disjoint(vertices + 1, -1);

        for(const auto edge : edges){
            int src = edge[0]; int dst = edge[1];

            if(disjoint[src] > 0){
                while(disjoint[src] > 0){
                    src = disjoint[src];
                }
            } 

            if(disjoint[dst] > 0){
                while(disjoint[dst] > 0){
                    dst = disjoint[dst];
                }
            }

            if(src == dst){
                redundant = edge;
                continue;
            }

            disjoint[src] += disjoint[dst];
            disjoint[dst] = src;
        }
        return redundant;
    }
};
