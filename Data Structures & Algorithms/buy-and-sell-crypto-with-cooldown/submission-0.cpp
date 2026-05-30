class Solution {
public:
    vector<vector<vector<int>>> memo;
    //will hold day, hold, cool

    vector<int> prices;

    int maxProfit(vector<int>& prices) {
        this->memo = vector(prices.size(), vector(2, vector(2, -1)));
        this->prices = prices;

        return dp(0, false, false);
    }

    int dp(int i, bool hold, bool cool){
        if(i >= prices.size()) return 0;
        if(memo[i][hold][cool] != -1) return memo[i][hold][cool];

        int ans = 0;
        if(hold){
            ans = max(dp(i+1, true, false), prices[i] + dp(i+1, false, true));
        } else if (!hold && !cool){
            ans = max(dp(i+1, false, false), -prices[i] + dp(i+1, true, false));
        } else {
            ans = dp(i+1, false, false);
        }
        memo[i][hold][cool] = ans;
        return ans;
    }
};
