class Solution {
public:
    vector<int> cost;
    vector<int> totalCost;
    int minCostClimbingStairs(vector<int>& cost) {
        this->cost = cost;
        totalCost = vector(cost.size() + 1, -1);
        return minCost(cost.size());
    }


    int minCost(int i) {
        if ( i == 0 ) { return 0; }
        if ( i == 1 ) { return 0; }

        if ( totalCost[i] != -1 ) { return totalCost[i]; }

        int sumCost = min(cost[i-1] + minCost(i-1), cost[i-2] + minCost(i-2));

        totalCost[i] = sumCost;
        return sumCost;
    }



    /*
    minCost(i) = the minimum cost to climb from floor 0 to i

    base case: 
        if i == 0 return 0
        if i == 1 return 0

        minCost(i) = min(totalCost[i-1] + minCost(i-1), totalCost[i-2] + minCost(i-2))

    */
};
