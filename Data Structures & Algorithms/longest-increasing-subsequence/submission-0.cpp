class Solution {
public:
    vector<int> memo;
    vector<int> nums;


    int lengthOfLIS(vector<int>& nums) {
        this->nums = nums;
        this->memo = vector(nums.size(), -1); memo.back() = 1;

        int ans = -1;
        for(int i = 0; i<nums.size(); i++){
            ans = max(ans, dp(i));
        
        }
        return ans;
        

    }

    int dp(int index){
        if(index >= nums.size()) return 0;
        if(index == nums.size() - 1) return 1;

        if(memo[index] != -1) return memo[index];

        int ans = 1;
        for(int j = index+1; j<nums.size(); j++){
            if(nums[j] > nums[index]){
                ans = max(ans, 1+dp(j));
            }
        }
        memo[index] = ans;
        return ans;
    }
};
