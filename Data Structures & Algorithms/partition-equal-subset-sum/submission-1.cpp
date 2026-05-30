class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2 == 1) return false;

        int target = sum/2;
        int i = 0;
        bool found = false;
        int cur = 0;
        backtrack(cur, i, found, target, nums);
        return found;
    }
    void backtrack(int cur, int i, bool& found, const int target, const vector<int>& nums){
        if(cur == target){
            found = true;
            return;
        }
        for(int j = i; j<nums.size(); j++){
            backtrack(cur+nums[j], j+1, found, target, nums);
        }
    }
};
