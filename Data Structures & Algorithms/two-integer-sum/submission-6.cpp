class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> comp_map;

        for ( size_t i{}; i < nums.size(); i++ ) {
            if ( comp_map.count(target - nums[i] ) ) return vector<int>{comp_map[target-nums[i]], i};
            
            comp_map[nums[i]] = i;
        }

        return vector<int>();

    }
};
