class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> disjointSet(n+1, -1);

        for ( auto e : edges ) {
            int vA = e[0];
            int vB = e[1];

            //vA and vB represent the index (node) and their value
            // dS[vX] represents their size 

            //we must loop until their value is negative
            while ( disjointSet[vA] > 0 ) {
                vA = disjointSet[vA];
            }

            while ( disjointSet[vB] > 0 ) {
                vB = disjointSet[vB];
            }

            //if they are the same index this is THE 
            // redundant edge

            if ( vA == vB ) {
                return e;
            }

            //o.w we must merge the two components
            // we will say vA always wins

            //update the value of vA
            // -x + -y = -(x+y)
            disjointSet[vA] += disjointSet[vB];

            //tell vB to point to node vA
            disjointSet[vB] = vA;
        }
    }
};
