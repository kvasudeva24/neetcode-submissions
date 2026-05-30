class Solution {
public:
    vector<int> nums;

    int findTargetSumWays(vector<int>& nums, int target) {
        this->nums = nums;     

        int ans = 0;
        int curSum = 0;
        int i = 0;
        backtrack(curSum, ans, i, target);
        return ans;
    }

    void backtrack(int curSum, int& ans, int i, const int& target){
        if(i == nums.size()){
            if(curSum == target)ans++;
            return;
        }

        backtrack(curSum + nums[i], ans, i+1, target);
        backtrack(curSum - nums[i], ans, i+1, target);
    }
};
