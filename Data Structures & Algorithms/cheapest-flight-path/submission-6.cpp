class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    
        vector<int> seen(n, -1);
        seen[src] = 0;

        for ( int i = 0; i <= k; i++ ) {
            vector<int> curIter = seen;
            for ( auto flight : flights ) {
                int edgeSrc = flight[0];
                int edgeDest = flight[1];
                int edgePrice = flight[2];

                if ( seen[edgeSrc] == -1 ) { continue; }

                if ( curIter[edgeDest] == -1 ) {
                    curIter[edgeDest] = seen[edgeSrc] + edgePrice;
                } else {
                    curIter[edgeDest] = min(seen[edgeSrc] + edgePrice, curIter[edgeDest]);
                }
            }
            seen = curIter;
        }
        return seen[dst];
    }
};
