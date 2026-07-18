class Solution {
public:
    vector<int> nums;
    vector<vector<int>> totalMoney;
    int rob(vector<int>& nums) {
        this->nums = nums;
        totalMoney = vector(nums.size(), vector(2, -1));
        return maxMoney(0, false);
    }

    int maxMoney(int i, bool robbedFirst) {
        if ( i >= nums.size() ) { return 0; }

        if ( totalMoney[i][robbedFirst] != -1 ) { return totalMoney[i][robbedFirst]; } 

        int money = 0;
        //if i is the last index
        if ( i == nums.size() - 1 ) {
            money = (robbedFirst == true) ? 0 : nums[i];

        } else if ( i == 0 ) {
            int rob = nums[i] + maxMoney(i+2, true);
            int skip = maxMoney(i+1, false);

            money = max(rob, skip);

            cout << "Most money @ house " << i << " is " << money << endl;

        } else {
            money = max(nums[i] + maxMoney(i+2, robbedFirst), maxMoney(i+1, robbedFirst)); 
            cout << "Most money @ house " << i << " is " << money << endl;
        }

        totalMoney[i][robbedFirst] = money;
        return money;

    }


    /*
    maxMoney(i, robbedLast) = most money we can obtain by robbing houses where the available houses
                              are [i, n]

                              i = the house we are one
                              robbedLast = boolean that tells us if we robbed the last house

    
    base case:
        if ( i > n ) return 0

        (money[i]) & set robbedLast to true
            if i == n

        
        max(maxMoney(i+2, robbedLast), maxMoney(i+1, robbedLast)) 
            if we choose first option make sure to set global to true
            if i == 0

        
        max(nums[i] + maxMoney(i+2, robbedLast), maxMoney(i+1, robbedLast)) 
            o.w

    */
};
