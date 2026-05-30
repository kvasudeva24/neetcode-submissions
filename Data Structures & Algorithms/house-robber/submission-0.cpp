class Solution {
public:
    vector<int> cache;

    int rob(vector<int>& nums) {
        cache = vector(nums.size(), -1);

        return dp(nums.size() - 1, nums);
    }

    int dp(int house, const vector<int>& nums){
        if(house == 0) return nums[house];
        if(house == 1) return max(nums[house - 1], nums[house]);

        if(cache[house] != -1) return cache[house];

        int ans = max(dp(house - 2, nums) + nums[house], dp(house -1, nums));
        cache[house] = ans;

        return ans;

    }
};
