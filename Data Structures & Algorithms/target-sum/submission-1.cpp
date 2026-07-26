class Solution {
public:
    vector<vector<int>> numWays;
    vector<int> nums;
    int target;

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for ( int num : nums ) {
            sum += abs(num);
        }

        numWays = vector(nums.size(), vector(2*sum+1, -1));
        this->nums = nums;
        this->target = target + sum;
        return numWaysTarget(0, sum);
    }

    int numWaysTarget(int i, int amt) {
        if ( i == nums.size() && amt == target ) {
            return 1;
        } else if ( i == nums.size() ) {
            return 0;
        }


        int ways = numWaysTarget(i+1, amt+nums[i]) + 
                   numWaysTarget(i+1, amt-nums[i]);



        return ways;
    }
};
