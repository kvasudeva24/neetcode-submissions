class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int helper = 0x0;
        for(int num : nums){
            helper = helper ^ num;
        }
        return helper;
    }
};
