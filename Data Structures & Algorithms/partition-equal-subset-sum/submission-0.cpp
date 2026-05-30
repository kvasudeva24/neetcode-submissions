class Solution {
public:
    vector<int> nums;
    bool canPartition(vector<int>& nums) {
        this->nums = nums;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;

        int half = sum / 2;
        int cur = 0;
        int i = 0;
        bool found = false;

        backtrack(cur, i, half, found);
        return found;
    }

    void backtrack(int cur, int i, const int& trgt, bool& found){
        if(cur == trgt){
            found = true;
            return;
        }

        for(int j = i; j<nums.size(); j++){
            if(cur + nums[j] > trgt){
                continue;
            } else {
                cur += nums[j];
                backtrack(cur, j+1, trgt, found);
                cur -= nums[j];
            }
        }
    }
};
