class Solution {
public:
    vector<vector<int>> numWays;
    vector<int> coins;

    int change(int amount, vector<int>& coins) {
        numWays = vector(coins.size(), vector(amount+1, -1));
        this->coins = coins;

        return numChange(0, amount);
    }

    int numChange(int i, int amt) {
        if ( amt == 0 ) { return 1; }

        if ( amt < 0 ) { return 0; }

        if ( i == coins.size() ) { return 0; }

        if ( numWays[i][amt] != -1 ) { return numWays[i][amt]; }

        int ways = numChange(i, amt-coins[i]) + numChange(i+1, amt);
        numWays[i][amt] = ways;
        return ways;

    }
};
