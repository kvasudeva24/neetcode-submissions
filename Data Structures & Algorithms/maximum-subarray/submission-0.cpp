class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0; int ans = nums[0];
        for(int num : nums){
            sum = max(sum, 0);
            sum+=num;
            ans = max(ans,  sum);
        }
        return ans;
    }
};
