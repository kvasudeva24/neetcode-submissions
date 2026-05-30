class Solution {
public:
    vector<int> cost;

    int minCostClimbingStairs(vector<int>& cost) {
        this->cost = cost;
        int n = cost.size();
        vector<int> sum_cost(n+1, INT_MAX);
        return minCost(sum_cost, n);
    }

    int minCost(vector<int>& sum_cost, int i) {
        if ( i <= 1 ) return 0;

        if ( sum_cost[i] != INT_MAX ) { return sum_cost[i]; }



        int one = minCost(sum_cost, i-1) + cost[i-1];
        int two = minCost(sum_cost, i-2) + cost[i-2];

        int result = min(one, two);
        sum_cost[i] = result;
        return result;

    }
};
