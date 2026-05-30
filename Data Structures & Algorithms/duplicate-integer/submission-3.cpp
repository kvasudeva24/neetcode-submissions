class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numbers;
        for ( size_t i = 0; i < nums.size(); i++ ) {
            if ( numbers.count(nums[i]) ) return true;
            numbers.insert(nums[i]);
        }
        return false;
    }
};