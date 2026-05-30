class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int early_price = prices[0];

        for ( int i = 0; i < prices.size(); i++ ) {
            if ( prices[i] < early_price ) { early_price = prices[i]; }
            else { profit = max(profit, prices[i] - early_price); }
        }
        return profit;
    }
};
