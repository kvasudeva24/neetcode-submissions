class Solution {
public:
    int n;

    int rob(vector<int>& nums) {
        this->n = nums.size();

        vector<int> money(n, -1);
        return MaxMoney(money, nums, 0);
    }

    int MaxMoney(vector<int>& money, const vector<int>& house, int i ) {
        if ( i >= n ) { return 0; }

        if ( money[i] != -1 ) { return money[i]; }

        int option1 = MaxMoney(money, house, i+1);
        int option2 = house[i] + MaxMoney(money, house, i+2);

        int result = max(option1, option2);
        money[i] = result;
        return result;
    }
};
