class Solution {
public:
    vector<int> memo;
    int minCostClimbingStairs(vector<int>& cost) {
        this->memo = vector(cost.size() + 1, INT_MAX);
        memo[0] = 0; memo[1] = 0;
        return dp(cost.size(), cost);   
    }

    int dp(int i, const vector<int>& cost){
        if(memo[i] != INT_MAX) return memo[i];

        int ans = INT_MAX;
        ans = min(cost[i-1]+dp(i-1, cost), cost[i-2]+dp(i-2, cost));
        memo[i] = ans;
        return ans;
    }
};
