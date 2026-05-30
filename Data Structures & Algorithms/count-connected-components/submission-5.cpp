class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> disjoint (n, -1);
        for(auto e : edges){
            int node1 = e[0];
            int node2 = e[1];

            while(disjoint[node1] >= 0){
                node1 = disjoint[node1];
            }

            while(disjoint[node2] >= 0){
                node2 = disjoint[node2];
            }

            cout << node1 << endl;
            cout << node2 << endl;
            if(node1 == node2) continue;

            disjoint[node1] += disjoint[node2];
            disjoint[node2] = node1;
        }
        int counter = 0;
        for(int node : disjoint) if(node < 0) counter++;

        return counter;
    }
};
