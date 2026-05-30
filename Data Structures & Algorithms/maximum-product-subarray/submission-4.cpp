class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMin = 1;
        int curMax = 1;
        int res = nums[0];

        for(int num : nums){
            int tmp = num * curMax;
            curMax = max(max(tmp, curMin * num), num);
            curMin = min(min(tmp, curMin * num), num);
            res = max(res, curMax);
        }
        return res;
    }
};
