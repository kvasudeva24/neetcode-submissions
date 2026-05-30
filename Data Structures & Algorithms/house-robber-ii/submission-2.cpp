class Solution {
public:
    int n;
    int rob(vector<int>& nums) {
        this->n = nums.size();

        vector<vector<int>> money(n, vector(2, -1));
        return maxMoney(0, false, money, nums);
    }

    int maxMoney(int i, bool robbed, vector<vector<int>>& money, vector<int>& nums) {
        if ( i >= n ) { return 0; }
        if ( money[i][robbed] != -1 ) { return money[i][robbed]; }

        if ( i == n-1 && robbed == true ) { return 0; }

        int skip = maxMoney(i+1, robbed, money, nums);
        int rob = -1;
        if ( i == 0 ) {
            rob = maxMoney(i+2, true, money, nums) + nums[i];
        } else {
            rob = maxMoney(i+2, robbed, money, nums) + nums[i];
        }
        int result = max(skip, rob);
        bool flag = ( result == skip || i != 0 ) ? robbed : true;
        money[i][flag] = result;
        return result;
    }
};
